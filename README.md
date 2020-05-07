#   **SERVER OF RHEDA-MESSENGER**
***

### Настройка проекта
##### Прежде чем приступить к разработке следует выполнить следующие действия:
* После загрузки репозитория необходимо запустить файл _install_virtualenv.h_
```bash
sudo chmod +x install_virtualenv.sh
sudo ./install_virtualenv.sh
```
* Данный скрипт обновит Python до последней актуальной версии, установит
виртуальное окружение и все необхоимые библиотеки
* Внести изменения в файл local_settings.example и сохранить его в той же
директории в файл local_settings.py
* SECRET_KEY можно сгенерировать на [сайте](https://djecrety.ir/)
* Активировать виртуальное окружение _rheda-env_:
```bash
source rheda-env/bin/activate
```
