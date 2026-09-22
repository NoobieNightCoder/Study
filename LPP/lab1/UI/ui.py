import UI.menu as menu
import UI.input as input


def main_menu(state) -> int:
    menu.print_status(state)

    menus_count = len(menu.MENU_OPTIONS)
    for i in range(1, menus_count + 1):
        print(i, ". ", menu.MENU_OPTIONS[i - 1][0], sep="")

    choice = input.choice_input()
    return_status = 0

    if choice > 0 and choice <= menus_count:
        try:
            return_status = menu.MENU_OPTIONS[choice - 1][1](state)
        except (ValueError, OSError) as error:
            print(error)
    else:
        print("Ошибка: неверный ввод!")

    return return_status