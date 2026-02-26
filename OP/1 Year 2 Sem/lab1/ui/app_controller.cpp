#include "app_controller.h"

#include "../logic/logic.h"
#include <QByteArray>
#include <cstdlib>
#include <cstring>

AppController::ConversionResponse AppController::Convert(const QString& InputText, Base InputBase, Base OutputBase) {
    ConversionResponse Response;

    QByteArray InputBytes = InputText.toUtf8();
    const char* InputCString = InputBytes.constData();

    ConversionResult* LogicResult = logic_convert(InputCString, InputBase, OutputBase);

    if (!LogicResult) {
        Response.ErrorText = "Внутренняя ошибка памяти.";
        return Response;
    }

    if (LogicResult->error && LogicResult->error[0] != '\0') {
        Response.ErrorText = QString::fromUtf8(LogicResult->error);
        freeConversionResult(LogicResult);
        return Response;
    }

    if (LogicResult->result) {
        Response.ResultText = QString::fromUtf8(LogicResult->result);
    }

    freeConversionResult(LogicResult);
    return Response;
}

bool AppController::SwapValues(QString& InputText, Base& InputBase, QString& OutputText, Base& OutputBase, QString& ErrorText) {
    QByteArray InputBytes = InputText.toUtf8();
    QByteArray OutputBytes = OutputText.toUtf8();

    char* InputCString = nullptr;
    char* OutputCString = nullptr;

    if (!InputBytes.isEmpty()) {
        InputCString = (char*)malloc(InputBytes.size() + 1);
        memcpy(InputCString, InputBytes.constData(), InputBytes.size());
        InputCString[InputBytes.size()] = '\0';
    } else {
        InputCString = (char*)calloc(1,1);
    }

    if (!OutputBytes.isEmpty()) {
        OutputCString = (char*)malloc(OutputBytes.size() + 1);
        memcpy(OutputCString, OutputBytes.constData(), OutputBytes.size());
        OutputCString[OutputBytes.size()] = '\0';
    } else {
        OutputCString = (char*)calloc(1,1);
    }

    char* SwapError = nullptr;

    int Result = logic_swap(&InputCString, &InputBase, &OutputCString, &OutputBase, &SwapError);

    if (Result != 0) {
        if (SwapError) {
            ErrorText = QString::fromUtf8(SwapError);
            free(SwapError);
        } else {
            ErrorText = "Ошибка при перестановке.";
        }

        if (InputCString) free(InputCString);
        if (OutputCString) free(OutputCString);

        return false;
    }

    InputText = QString::fromUtf8(InputCString);
    OutputText = QString::fromUtf8(OutputCString);

    free(InputCString);
    free(OutputCString);

    return true;
}