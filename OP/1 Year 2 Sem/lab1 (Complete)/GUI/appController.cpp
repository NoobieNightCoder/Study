#include "appController.h"

#include "../BL/errorHandler.h"
#include "../BL/stringUtils.h"

#include <QByteArray>
#include <cstdlib>

static char* duplicateQStringAsUtf8(const QString& text) {
    QByteArray bytes = text.toUtf8();
    char* duplicated = duplicateString(bytes.constData());
    return duplicated;
}

static void freeCString(char* text) {
    if (text) free(text);
}

static void setErrorById(QString& errorText, errorID id) {
    errorText = QString::fromUtf8(getErrorMessage(id));
}

static int prepareSwapBuffers(const QString& inputText, const QString& outputText, char** inputBuffer, char** outputBuffer) {
    int status = 0;

    *inputBuffer = duplicateQStringAsUtf8(inputText);
    *outputBuffer = duplicateQStringAsUtf8(outputText);

    if (!*inputBuffer || !*outputBuffer)
        status = -1;

    return status;
}

static void releaseSwapResources(char* inputBuffer, char* outputBuffer, char* swapError) {
    freeCString(inputBuffer);
    freeCString(outputBuffer);
    freeCString(swapError);
}

static void setSwapErrorText(QString& errorText, char* swapError) {
    if (swapError)
        errorText = QString::fromUtf8(swapError);
    else
        setErrorById(errorText, ERROR_PARSING);
}



void AppController::setInputBase(Base input) {
    InputBase = input;
}

void AppController::setOutputBase(Base output) {
    OutputBase = output;
}

void AppController::setInputText(QString input) {
    InputText = input;
}

void AppController::setOutputText(QString output) {
    OutputText = output;
}

Base AppController::getInputBase() {
    return InputBase;
}

Base AppController::getOutputBase() {
    return OutputBase;
}

QString AppController::getInputText() {
    return InputText;
}

QString AppController::getOutputText() {
    return OutputText;
}

QString AppController::getErrorText() {
    return ErrorText;
}

void AppController::Convert() {
    QByteArray inputBytes = InputText.toUtf8();
    const char* inputCString = inputBytes.constData();
    ConversionResult* logicResult = logicConvert(inputCString, InputBase, OutputBase);
    ErrorText = NULL;

    if(logicResult) {
        if (logicResult->error && logicResult->error[0] != '\0')
            ErrorText = QString::fromUtf8(logicResult->error);
        else if (logicResult->result)
            OutputText = QString::fromUtf8(logicResult->result);
            
        freeConversionResult(logicResult);
    } else {
        setErrorById(ErrorText, ERROR_MEMORY);
    }
}

bool AppController::SwapValues() {
    bool isSuccess = true;
    char* inputCString = nullptr;
    char* outputCString = nullptr;
    char* swapError = nullptr;

    if (prepareSwapBuffers(InputText, OutputText, &inputCString, &outputCString) != 0) {
        isSuccess = false;
        setErrorById(ErrorText, ERROR_MEMORY);
    }

    if (isSuccess) {
        if (logicSwap(&inputCString, &InputBase, &outputCString, &OutputBase, &swapError) != 0) {
            isSuccess = false;
            setSwapErrorText(ErrorText, swapError);
        }
        else {
            InputText = QString::fromUtf8(inputCString);
            OutputText = QString::fromUtf8(outputCString);
        }
    }

    releaseSwapResources(inputCString, outputCString, swapError);
    return isSuccess;
}
