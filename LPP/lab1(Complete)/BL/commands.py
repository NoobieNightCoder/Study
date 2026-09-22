import os
import csv
import UI.input as input
import UI.print_table as printer
import BL.process_table as pt

def open_file(state) -> int:
    status = 0

    if not state["file_opened"]:
        filename = input.input_filename()
        file_size = os.path.getsize(filename) / 1024 / 1024

        if file_size < pt.MAX_FILE_SIZE_MB:
            with open(filename, 'r', newline="", encoding='utf-8') as file:
                headers, table_data, regions = pt.init(file)
            state["filename"] = filename
            state["file_opened"] = True
            state["headers"] = headers
            state["regions"] = regions
            state["table_data"] = table_data
            state["region"] = ""
            state["id"] = -1
        else:
            raise ValueError("Ошибка: файл слишком большой!")
    else:
        raise ValueError("Ошибка: файл уже открыт!")
    

    return status

def print_curr_table(state) -> int:
    status = 0

    if not state["file_opened"]:
        raise ValueError("Ошибка: нет файла!")

    target_table = pt.get_target_table(state["headers"], state["table_data"], state["region"])
    printer.print_table(target_table)

    return status

def type_region(state) -> int:
    status = 0

    if not state["file_opened"]:
        raise ValueError("Ошибка: нет файла!")

    state["region"] = input.input_region(state["regions"])

    return status

def type_column(state) -> int:
    status = 0

    if not state["file_opened"]:
        raise ValueError("Ошибка: нет файла!")

    state["id"] = input.input_id(state["headers"])

    return status

def calculate_stats(state) -> int:
    status = 0

    if not state["file_opened"]:
        raise ValueError("Ошибка: нет файла!")
    if not state["region"]:
        raise ValueError("Ошибка: регион не выбран!")
    if state["id"] < 0:
        raise ValueError("Ошибка: столбец не выбран!")

    target_table = pt.get_target_table(state["headers"], state["table_data"], state["region"])
    data = pt.get_data(state["table_data"], state["region"], state["id"])
    ans_table = pt.calc_stats(data)
    percentiles_table = pt.calc_percentiles(data, pt.PERCENTILE_STEP)
    printer.print_all_tables(target_table, ans_table, percentiles_table)
        
    return status

def close_file(state) -> int:
    status = 0

    if not state["file_opened"]:
        raise ValueError("Ошибка: нет файла!")

    state["id"] = -1
    state["region"] = ""
    state["headers"] = []
    state["regions"] = []
    state["table_data"] = []
    state["filename"] = ""
    state["file_opened"] = False

    return status

def exit_program(state) -> int:
    status = 1

    return status