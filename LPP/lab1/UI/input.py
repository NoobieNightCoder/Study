from pathlib import Path

def input_filename():
    while True:
        result = Path(input("Введите путь до файла ИЛИ его название (если файл находится в корневой папке проекта):\n"))
        if not result.exists() or not result.is_file():
            print("Ошибка: ошибка в названии/пути к файлу!")
        elif result.suffix.lower() != ".csv":
            print("Ошибка: неверный формат файла!")
        else:
            return result

def input_region(regions) -> str:
    for index, reg in enumerate(regions):
        print(f"{index + 1}. {reg}")

    while True:
        try:
            result = int(input("Введите номер региона: "))
            if result < 1 or result > len(regions):
                print("Ошибка: нет такого региона!")
            else:
                return regions[result - 1]
        except ValueError:
            print("Ошибка: нужно ввести число!")

def choice_input() -> int:
    while True:
        try:
            result = int(input())
            return result
        except ValueError:
            print("Ошибка: нужно ввести число!")

def input_id(headers) -> int:
    for index in range(2, len(headers)):
        print(f"{index + 1}. {headers[index]}")

    while True:
        try:
            result = int(input("Введине номер столбца: "))
            if result < 3 or result > len(headers):
                print("Ошибка: неверный столбец или столбца не существует!")
            else:
                return result - 1
        except ValueError:
            print("Ошибка: нужно ввести число!")
