import BL.commands as commands

MENU_OPTIONS = (
    #  NAME,                                     COMMAND             #
    [ "Открыть файл",                            commands.open_file           ],
    [ "Вывести таблицу",                         commands.print_curr_table    ],
    [ "Ввести регион",                           commands.type_region         ],
    [ "Ввести столбик",                          commands.type_column         ],
    [ "Выполнить расчет и вывести результат",    commands.calculate_stats     ],
    [ "Закрыть файл",                            commands.close_file          ],
    [ "Выйти из программы",                      commands.exit_program        ]
)

def print_status(state):
    print("Статус:")
    if state["file_opened"]:
        print("Открыт файл: ", state["filename"])
    else:
        print("Нет открытого файла")

    print("Выбран регион: ", end="")
    if state["region"]:
        print(state["region"])
    else:
        print("-")

    print("Выбран столбик: ", end="")
    if state["id"] >= 0:
        print(state["id"] + 1, "\n")
    else:
        print("-", "\n")