#!  /bin/bash

readonly SOURCE_FILE=./rheda-env/bin/activate

#Установка питона третьего, для тех, у кого нет
sudo apt install python3
sudo apt-get install python3-venv
sudo apt install python3-pip
pip3 install virtualenv

#Установка и активация виртуального окружения
python3 -m venv rheda-env
source ${SOURCE_FILE}

#Установка нужных для проекта пакетов внутри виртуального окружения
pip3 install djangorestframework


# После выполнения скрипта необходимо
# выполнить команду source rheda-env/bin/activate,
# так как виртуальное окружение сбрасывается после выполнения скрипта

# Если использовать PyCharm, то терминал среды разработки автоматически
# активирует виртуальное окружение
