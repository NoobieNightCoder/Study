import UI.ui as ui

# ЗАМЕЧАНИЯ:
# НУЖНО СДЕЛАТЬ ОБРАБОТКУ РАЗНЫХ ТИПОВ ОШИБОК
# СДЕЛАТЬ ТЕКСТ ОШИБОК БОЛЕЕ ТОЧНЫМ ДЛЯ ПОЛЬЗОВАТЕЛЯ
# САМИМ ОБРАБОТАТЬ ОШИБКУ СВЯЗАННУЮ С НЕДОСТАТОЧНЫМ КОЛ-ВОМ СТРОК ДЛЯ ПОДСЧЕТА
# СДЕЛАТЬ ДОСТУПНЫМ ОБРАБОТКУ ФАЙЛА С РАЗДЕЛИТЕЛЕМ ВВИДЕ ;

def main():
    state = {
        "id": -1,
        "region": "",
        "filename": "",
        "file_opened": False,
        "headers": [],
        "regions": [],
        "table_data": []
    }
  
    status = 0
    while not status:
        status = ui.main_menu(state)

main()
