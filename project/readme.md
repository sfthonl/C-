<h1 align="center">Инженерный практикум</h1>

<hr>

<p align="center">
    <img src="logo.jpg" alt="logo" height="120" width="400"/>
    <img src="logo_2.jpg" alt="logo_2" height="120" width="200"/>
</p>

<h6 align="center">Работу выполнили студенты группы Б03-416</h6>

<h1 align="center"><a  href="https://solitairevue.firebaseapp.com">Демонстрация и описание проекта</a></h1>

##  Инструменты для создания проекта <h3>

- ## *C++*
   
- ## *FLTK lib*

- ## *Cmake*

## Описание проекта

<hr>

- ## cell.h
  <h4>Используется для создания элементов управления графического интерфейса, в нашем случае кнопок, имеет возможность взаимодействия с игровым процессом. Является основой для создания интерактивного игрового поля</h4>
- ## board.h
  <h4>Представляет поле в виде матриц целых чисел. Структура хранит текущее состояние игры</h4>
- ## game.h
  <h4>Объявляет структуру Game, а также зависимости от других заголовочных файлов. Он определяет, что будет содержать класс Game и какие методы у него есть, но не содержит самой логики этих методов</h4>
- ## visualboard.h
  <h4>Отвечает за оторбажение доски</h4>
- ## board.cpp
  <h4>board.cpp содержит реализацию методов структуры Board, которые объявлены в board.h. Он отвечает за то, как игровое поле работает (создание, проверка победы, хода)</h4>
- ## game.cpp
  <h4>Этот код реализует логику для игры. Управляет игровым полем, ходами, победой и ничьей.</h4>
- ## visualboard.cpp
  <h4>Реализует логику очистки доски, создание
  новой (в случае завершения игры)</h4>
- ## main.cpp
  <h4>Создаёт окно для игры, запускает
  игровой процесс</h4>
## Демонстрация работы программы
<p align="center">
<img src="https://github.com/sfthonl/C-/blob/main/gif.gif" width="80%"></p>
