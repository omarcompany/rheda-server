#   **SERVER OF RHEDA-MESSENGER**
***

### Настройка проекта

**Прежде чем приступить к разработке следует выполнить следующие действия:**
* Сделать скрипт _install_virtualenv.sh_ исполняемым и запустить его:
```bash
sudo chmod +x install_virtualenv.sh
sudo ./install_virtualenv.sh
```
***
Данный скрипт обновит Python до последней актуальной версии, установит виртуальное окружение и все необхоимые библиотеки
***
* Активировать виртуальное окружение _rheda-env_:
```bash
source rheda-env/bin/activate
```

* Применить миграции к базе данных, после чего запустить сервер:
```bash
python3 manage.py migrate
python3 manage.py runserver
```
