import UI.offsets as ofs

def print_header(reader, offset_list):
    fields = next(reader)
    for i, field in enumerate(fields):
        print(f"|{field:^{ofs.GLOBAL_OFFSET + offset_list[i]}}", end="")
    print("|")
    print("-" * (ofs.GLOBAL_OFFSET * (len(fields) + 1) + sum(offset_list)))

def print_data(reader, offset_list):
    for row in reader:
        for i, elem in enumerate(row):
            print(f"|{elem:^{ofs.GLOBAL_OFFSET + offset_list[i]}}", end="")
        print("|")

def print_table(table_data):
    if not table_data:
        print("Ошибка: таблица пустая!")
    else:
        offset_list = ofs.get_offset_list(table_data)
        it = iter(table_data)
        print_header(it, offset_list)
        print_data(it, offset_list)

def print_all_tables(region_table_data, ans_table_data, perc_table_data):
    print("Таблица с фильтром по региону:\n")
    print_table(region_table_data)
    print("\n\n\nМаксимальное, Минимальное, Медиана:\n")
    print_table(ans_table_data)
    print("\n\n\nПерцентили:\n")
    print_table(perc_table_data)
