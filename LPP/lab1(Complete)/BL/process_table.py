import csv
import statistics

PERCENTILE_STEP = 5
MAX_FILE_SIZE_MB = 50

def init(file):
    reader = csv.reader(file)

    try:
        headers = next(reader)
    except StopIteration:
        raise ValueError("Ошибка: CSV файл пуст!")

    if len(headers) < 3:
        raise ValueError("Ошибка: CSV файл должен содержать минимум 3 колонки!")

    table_data = []
    regions = []

    for row_number, row in enumerate(reader, start=2):
        if len(row) != len(headers):
            raise ValueError(f"Ошибка: недостаточно данных в строке {row_number}")

        if not row[1]:
            raise ValueError(f"Ошибка: пустой регион в строке {row_number}")

        try:
            for value in row[2:]:
                if value:
                    float(value)
        except ValueError:
            raise ValueError(f"Ошибка: неверный тип данных в строке {row_number}")

        table_data.append(row)
        if row[1] not in regions:
            regions.append(row[1])

    if not table_data:
        raise ValueError("CSV файл пуст")

    regions.sort()
    return headers, table_data, regions

def get_target_table(headers, table_data, target_region = ""):
    target_table = [headers]

    for row in table_data:
        if not target_region:
            target_table.append(row)
        elif row[1] == target_region:
            target_table.append(row)

    return target_table

def get_data(table_data, target_region, id):
    data = []

    for row in table_data:
        if row[1] == target_region:
            if row[id]:
                data.append(float(row[id]))

    if not data:
        raise ValueError("Ошибка: нет данных для выбранного региона!")

    return data

def calc_stats(data):
    ans_table = [
        [" ", "Значение"],
        ["Максимум", max(data)],
        ["Минимум", min(data)],
        ["Медиана", statistics.median(data)]
    ]

    return ans_table

def calc_percentiles(data, percentile_step):
    if percentile_step <= 0 or percentile_step >= 100 or 100 % percentile_step != 0:
        raise ValueError("Ошибка: неправильный шаг для перцентеля!")

    q_points = statistics.quantiles(data, n=(100 // percentile_step))
    percentiles_table = [["Перцентиль", "Значение"]]

    percentiles_table.append(["0%", min(data)])

    for index, val in enumerate(q_points):
        percent_name = f"{(index + 1) * percentile_step}%"
        percentiles_table.append([percent_name, round(val, 2)])

    percentiles_table.append(["100%", max(data)])

    return percentiles_table
