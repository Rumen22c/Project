# Project
project about clean code
Домашно по качествен програмен код
 Румен Минчев, софтуерно инженерство, втори курс, факултетен номер 62264
Разгледах проект на George Harter. Това е линк към проекта му     https://gist.github.com/geocachecs/d8d2f402b0843231231b 
Започнах с прекръстването на файлът main.cpp в ChessProject.cpp , защото исках да има уникално име, с което да се различава от другите ми  проекти. 
Променливата за започване на играта беше кръстена s. 
string s; 
Това според мен не е качествено кръщаване на променлива, защото по никакъв начин не ни показва какво е предназначението на тази променлива. Според мен би било правилно да се прекръсти на startGame
string startGame;
Ако потребителят иска да изиграе още една игра, трябва да въведе y , тази стойност отива отново в startGame. Според мен по-добре би било да се използва друга променлива, защото е добра практика една променлива да се използва за едно точно определено нещо. А стартирането на игра и желанието за се изиграе още една игра са две различни неща. Затова според мен е добре да се използва нова променлива anotherGame, която да използваме за тази цел. Колебаех се дали да не използваме булева променлива, но сметнах че за потребителят ще е по-ясно "Do you want to play again? (y for yes, anything else for no) " , отколкото "Do you want to play again? (1 for yes, anything else for no) ".
Освен това смятам, че b не е добро име за променлива от тип Board. Смятам, че по-подходящо би било board.
Преминаваме към chess.h . На мен лично FIGURE ми е по-ясно от PIECE, затова ще го променя. Координатите x и y написани просто така не мисля, че са достатъчно ясни, може би по-добре щеше да е ако са  coordinateX и coordinateY. Същото се отнася и за методите setX, setY , getX и getY, ако бяха в клас Point, имената им щяха да са добре, но сега не. По-добре е според мен да се направи отделен клас Position, koйто ще съдържа int x и int y и ще ни показва в кое квадратче от играта сме, затова мисля, че ще е добре да го кръстим postionOnTheTable. Във всеки метод ,в който участват x и y ще заместим съответно с postionOnTheTable.getCoordinateX() и postionOnTheTable.getCoordinateY().
Разглеждаме void Board::printBoard(). Тук има switch, което означава, че този метод ще прави n неща, в нашия случай 8, и не само това, ами и ще се изпълнява на всеки ход. Добра практика е тук да се използва полиморфизъм. При нас обектите не са самите фигури, а самите квадратчета на играта, следователно би било почти невъзможно (поне за мен) да се направи тук полиморфизъм. Според мен функцията е много дълга би било добре този switch да бъде изнесен във функция printFigures(Figure,Color).
След като прегледах кода няколко пъти смятам, че щеше да е по-добре, ако всяка отделна фигура беше в отделен клас, тъй като полиморфизмът тогава щеше да е много лесен и естествен за създаване. Например в bool Board::makeMove(Position  startPosition, Position endPosition) имаме switch, който за всяка фигура извиква функция за преместването й. Ако имахме отделен клас за всяка функция, можехме с полиморфизъм да извършим тази дейност, което би ни улеснило и би вдигнало качестватото на кода.
