GLOBAL_OFFSET = 4

def calc_offset(array: list[str]) -> int:
    max_length = 0
    for obj in array:
        if len(obj) > max_length:
            max_length = len(obj)

    return max_length

def get_offset_list(table_data) -> list[int]:
    offset_list = []

    if table_data:
        column_num = len(table_data[0])
        for i in range(column_num):
            column = []
            for row in table_data:
                column.append(str(row[i]))

            column_offset = calc_offset(column)
            offset_list.append(column_offset)

    return offset_list
