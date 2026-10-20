import csv
import pandas as pd
from pathlib import Path

MAX_FILE_SIZE = 5 * 1024 * 1024

def read_file(filename: str):
    path = Path(filename)

    if not path.exists():
        raise FileNotFoundError("Файл не найден")

    if not path.is_file() or path.suffix.lower() != ".csv":
        raise ValueError("Неверный формат файла")

    file_size = path.stat().st_size

    if file_size == 0:
        raise ValueError("Файл пустой")

    if file_size > MAX_FILE_SIZE:
        raise ValueError("Размер файла превышает лимит 5 МБ.")

    try:
        with open(path, "r", encoding="utf-8", newline="") as file:
            sample = file.read(4096)

            try:
                dialect = csv.Sniffer().sniff(sample, delimiters=",;")
            except csv.Error:
                raise ValueError("Не удалось определить разделитель")

            file.seek(0)
            reader = csv.reader(file, dialect)

            try:
                header = next(reader)
                first_row = next(reader)
            except StopIteration:
                raise ValueError("Файл пустой")

            if not header or all(cell.strip() == "" for cell in header):
                raise ValueError("В файле отсутствуют заголовки")


            column_count = len(header)
            if len(first_row) != column_count:
                raise ValueError("Файл поврежден")

            for _, row in enumerate(reader, start=2):
                if len(row) != column_count:
                    raise ValueError("Файл поврежден")

    except UnicodeDecodeError:
        raise ValueError("Не удалось прочитать файл")

    except csv.Error:
        raise ValueError("Файл поврежден")


    try:
        df = pd.read_csv(path, sep=dialect.delimiter)
    except pd.errors.ParserError:
        raise ValueError("Файл поврежден")

    return df