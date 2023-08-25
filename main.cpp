#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <queue>
#include <chrono>
#include "board.h"
#include "leaderboard.h"
using namespace chrono;
using namespace std;

void setText(sf::Text &text, float x, float y){
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(x,y));
}
sf::Texture loadTexture(const string& textureFile){
    sf::Texture texture;
    if (!texture.loadFromFile(textureFile)){
        cout << "Error loading texture" << textureFile << endl;
    }
    return texture;
}
void positionTileSprites(sf::Sprite* sprites, int tileCount, int tileWidth, int tileHeight, int tilesPerRow){
    int rowIndex = 0;
    int colIndex = 0;
    for (unsigned int i = 0; i < tileCount; ++i){
        sprites[i].setPosition(colIndex * (tileWidth), rowIndex*(tileHeight));
        ++colIndex;
        if (colIndex == tilesPerRow){
            colIndex = 0;
            ++rowIndex;
        }
    }
}
void positionMineSprites(sf::Sprite* sprites, int tileCount, int tileWidth, int tileHeight, int tilesPerRow, const vector<Tile> Mines) {
    int rowIndex = 0;
    int colIndex = 0;
    int IndexSprites = 0;
    for (int i =0; i < tileCount; ++i){
        if (Mines.at(i).mine){
            sprites[IndexSprites].setPosition(colIndex * (tileWidth), rowIndex*(tileHeight));
            ++IndexSprites;
        }
        ++colIndex;
        if (colIndex == tilesPerRow){
            colIndex = 0;
            ++rowIndex;
        }
    }

}
void positionNumberAndMines(vector<sf::Sprite>& sprites, const vector<Tile> NumberMines, const vector<sf::Sprite>NumberSprites, sf::Sprite mine, int tileCount, int tileWidth, int tileHeight, int tilesPerRow){
    int rowIndex = 0;
    int colIndex = 0;
    sf::Sprite TempSprite;
    for (int i = 0; i < tileCount; ++i){
        if (NumberMines.at(i).hasnumber){
            if (NumberMines.at(i).number == 1){
                TempSprite = NumberSprites.at(0);
                TempSprite.setPosition(colIndex * (tileWidth), rowIndex*(tileHeight));
                sprites.push_back(TempSprite);
            }
            else if (NumberMines.at(i).number == 2){
                TempSprite = NumberSprites.at(1);
                TempSprite.setPosition(colIndex * (tileWidth), rowIndex*(tileHeight));
                sprites.push_back(TempSprite);
            }
            else if (NumberMines.at(i).number == 3){
                TempSprite = NumberSprites.at(2);
                TempSprite.setPosition(colIndex * (tileWidth), rowIndex*(tileHeight));
                sprites.push_back(TempSprite);
            }
            else if (NumberMines.at(i).number == 4){
                TempSprite = NumberSprites.at(3);
                TempSprite.setPosition(colIndex * (tileWidth), rowIndex*(tileHeight));
                sprites.push_back(TempSprite);
            }
            else if (NumberMines.at(i).number == 5){
                TempSprite = NumberSprites.at(4);
                TempSprite.setPosition(colIndex * (tileWidth), rowIndex*(tileHeight));
                sprites.push_back(TempSprite);
            }
            else if (NumberMines.at(i).number == 6){
                TempSprite = NumberSprites.at(5);
                TempSprite.setPosition(colIndex * (tileWidth), rowIndex*(tileHeight));
                sprites.push_back(TempSprite);
            }
            else if (NumberMines.at(i).number == 7){
                TempSprite = NumberSprites.at(6);
                TempSprite.setPosition(colIndex * (tileWidth), rowIndex*(tileHeight));
                sprites.push_back(TempSprite);
            }
            else if (NumberMines.at(i).number == 8){
                TempSprite = NumberSprites.at(7);
                TempSprite.setPosition(colIndex * (tileWidth), rowIndex*(tileHeight));
                sprites.push_back(TempSprite);
            }
        }
        if (NumberMines.at(i).mine){
            TempSprite = mine;
            TempSprite.setPosition(colIndex*(tileWidth), rowIndex*(tileHeight));
            sprites.push_back(TempSprite);
        }
        ++colIndex;
        if (colIndex == tilesPerRow){
            colIndex = 0;
            ++rowIndex;
        }
    }
}
bool mousePositionButton(sf::Sprite spriteButton, sf::Vector2i mousePos){
    sf::FloatRect boundsButton = spriteButton.getGlobalBounds();
    return boundsButton.contains(sf::Vector2f(mousePos));
}
void positionFlag(sf::Sprite& flag_sprite, int tileIndex, int tileCount, int tileWidth, int tileHeight, int tilesPerRow){
    int rowIndex = 0;
    int colIndex = 0;
    for (int i = 0; i < tileCount; ++i){
        if (i == tileIndex){
            flag_sprite.setPosition(colIndex*(tileWidth), rowIndex*(tileHeight));
        }
        ++colIndex;
        if (colIndex == tilesPerRow){
            colIndex = 0;
            ++rowIndex;
        }
    }
}
void positionNMT(vector<sf::Sprite>& sprites, const vector<Tile> NumberMines, const vector<sf::Sprite>NumberSprites, sf::Sprite emptyTile, sf::Sprite mine, int tileCount, int tileWidth, int tileHeight, int tilesPerRow){
    int rowIndex = 0;
    int colIndex = 0;
    sf::Sprite TempSprite;
    for (int i = 0; i < tileCount; ++i){
        if (NumberMines.at(i).hasnumber){
            if (NumberMines.at(i).number == 1){
                TempSprite = NumberSprites.at(0);
                TempSprite.setPosition(colIndex * (tileWidth), rowIndex*(tileHeight));
                sprites.push_back(TempSprite);
            }
            else if (NumberMines.at(i).number == 2){
                TempSprite = NumberSprites.at(1);
                TempSprite.setPosition(colIndex * (tileWidth), rowIndex*(tileHeight));
                sprites.push_back(TempSprite);
            }
            else if (NumberMines.at(i).number == 3){
                TempSprite = NumberSprites.at(2);
                TempSprite.setPosition(colIndex * (tileWidth), rowIndex*(tileHeight));
                sprites.push_back(TempSprite);
            }
            else if (NumberMines.at(i).number == 4){
                TempSprite = NumberSprites.at(3);
                TempSprite.setPosition(colIndex * (tileWidth), rowIndex*(tileHeight));
                sprites.push_back(TempSprite);
            }
            else if (NumberMines.at(i).number == 5){
                TempSprite = NumberSprites.at(4);
                TempSprite.setPosition(colIndex * (tileWidth), rowIndex*(tileHeight));
                sprites.push_back(TempSprite);
            }
            else if (NumberMines.at(i).number == 6){
                TempSprite = NumberSprites.at(5);
                TempSprite.setPosition(colIndex * (tileWidth), rowIndex*(tileHeight));
                sprites.push_back(TempSprite);
            }
            else if (NumberMines.at(i).number == 7){
                TempSprite = NumberSprites.at(6);
                TempSprite.setPosition(colIndex * (tileWidth), rowIndex*(tileHeight));
                sprites.push_back(TempSprite);
            }
            else if (NumberMines.at(i).number == 8){
                TempSprite = NumberSprites.at(7);
                TempSprite.setPosition(colIndex * (tileWidth), rowIndex*(tileHeight));
                sprites.push_back(TempSprite);
            }
        }
        else if (NumberMines.at(i).mine){
            TempSprite = mine;
            TempSprite.setPosition(colIndex*(tileWidth), rowIndex*(tileHeight));
            sprites.push_back(TempSprite);
        }
        else if (NumberMines.at(i).empty){
            TempSprite = emptyTile;
            TempSprite.setPosition(colIndex*(tileWidth), rowIndex*(tileHeight));
            sprites.push_back(TempSprite);
        }
        ++colIndex;
        if (colIndex == tilesPerRow){
            colIndex = 0;
            ++rowIndex;
        }
    }
}
vector<sf::Sprite> findEmptyRecursive(vector<Tile> AllTiles, vector<sf::Sprite> NumbersMinesEmpty, int clickedIndex, int rows, int cols, int tiles, sf::Sprite* sprites, vector<sf::Sprite>& revealedTiles, vector<sf::Sprite> placedFlags, vector<sf::Sprite> tilesClicked) {
    vector<sf::Sprite> result;
    vector<bool> visited(tiles, false);
    queue<int> q;
    q.push(clickedIndex);
    visited[clickedIndex] = true;
    result.push_back(NumbersMinesEmpty.at(clickedIndex));
    revealedTiles.push_back(sprites[clickedIndex]);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        int row = current / cols;
        int col = current % cols;
        for (int i = row - 1; i <= row + 1; i++) {
            for (int j = col - 1; j <= col + 1; j++) {
                int index = i * cols + j;
                if (i >= 0 && i < rows && j >= 0 && j < cols && !visited[index]) {
                    visited[index] = true;
                    bool flagPlaced = false;
                    bool tileClickedAlready = false;
                    Tile tile = AllTiles[index];
                    for (const auto & placedFlag : placedFlags){
                        if (NumbersMinesEmpty.at(index).getGlobalBounds() == placedFlag.getGlobalBounds()){
                            flagPlaced = true;
                            break;
                        }
                    }
                    for (const auto & j : tilesClicked){
                        if (NumbersMinesEmpty.at(index).getGlobalBounds() == j.getGlobalBounds()){
                            tileClickedAlready = true;
                        }
                    }
                    if ((tile.empty || tile.hasnumber) && !flagPlaced && !tileClickedAlready) {
                        sf::Sprite sprite = NumbersMinesEmpty.at(index);
                        result.push_back(sprite);
                        revealedTiles.push_back(sprites[index]);
                        if (tile.empty) {
                            q.push(index);
                        }
                    }
                }
            }
        }
    }
    return result;
}
int main()
{
    int columns;
    int rows;
    int mines;
    string userName;
    ifstream configFile("files/board_config.cfg");
    string line;
    if (configFile.is_open()){
        getline(configFile, line);
        columns = stoi(line);
        getline(configFile, line);
        rows = stoi(line);
        getline(configFile, line);
        mines = stoi(line);
        configFile.close();
    }
    else{
        cout << "Could not find config file" << endl;
        return 0;
    }

    int width, height, tiles;
    width = columns * 32;
    height = (rows * 32) + 100;
    tiles = columns * rows;
    sf::RenderWindow welcomeWindow(sf::VideoMode(width, height),
                                   "Welcome to Minesweeper", sf::Style::Close);
    sf::Font font;
    if (!font.loadFromFile("files/font.ttf")){
        cout << "Error loading font file" << endl;
        return 0;
    }

    sf::Text welcomeText;
    welcomeText.setFont(font);
    welcomeText.setString("WELCOME TO MINESWEEPER");
    welcomeText.setCharacterSize(24);
    welcomeText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    welcomeText.setFillColor(sf::Color::White);
    setText(welcomeText, width/2.0f, height/2.0f-150);

    sf::Text enterNameText;
    enterNameText.setFont(font);
    enterNameText.setString("Enter your name:");
    enterNameText.setCharacterSize(20);
    enterNameText.setStyle(sf::Text::Bold);
    enterNameText.setFillColor(sf::Color::White);
    setText(enterNameText, width/2.0f, height/2.0f - 75);

    sf::Text userInput;
    userInput.setFont(font);
    userInput.setString("|");
    userInput.setCharacterSize(18);
    userInput.setFillColor(sf::Color::Yellow);
    setText(userInput, width/2.0f, height/2.0f - 45);


    while (welcomeWindow.isOpen()){
        sf::Event event;
        while (welcomeWindow.pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:
                    welcomeWindow.close();
                    return 0;
                case sf::Event::TextEntered:
                    if (event.text.unicode < 128 && userInput.getString().getSize() < 11){
                        char letter = static_cast<char>(event.text.unicode);
                        if(isalpha(letter)){
                            string user_name = userInput.getString();
                            user_name.pop_back();
                            userInput.setString(user_name);
                            if(userInput.getString().getSize() == 0){
                                letter = toupper(letter);
                            }
                            else if (userInput.getString().getSize()>0){
                                letter = tolower(letter);
                            }
                            userInput.setString(userInput.getString() + letter);
                            userInput.setString(userInput.getString() + '|');
                            setText(userInput, width/2.0f, height/2.0f - 45);
                        }
                    }
                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Enter){
                        string user_name = userInput.getString();
                        user_name.pop_back();
                        user_name += "*";
                        userName = user_name;
                        if (userInput.getString().getSize() != 1){
                            welcomeWindow.close();
                        }
                    }
                    else if (event.key.code == sf::Keyboard::Backspace){
                        string user_name = userInput.getString();
                        if (user_name.size() != 1){
                            user_name.erase(user_name.size() - 2);
                            userInput.setString(user_name + "|");
                            setText(userInput, width/2.0f, height/2.0f - 45);
                        }
                    }
                    break;
            }
        }
        setText(userInput, width/2.0f, height/2.0f - 45);
        welcomeWindow.clear(sf::Color::Blue);
        welcomeWindow.draw(welcomeText);
        welcomeWindow.draw(enterNameText);
        welcomeWindow.draw(userInput);
        welcomeWindow.display();
    }
    bool pause = false;
    bool loss = false;
    bool win = false;
    bool debug = false;
    bool GameOver = false;
    bool LeaderOpened = false;
    bool won = false;
    int correctFlags = 0;
    int numFlagsPlaced;
    int numTilesRevealed = 0;
    vector<sf::Sprite> flagsPlaced;
    vector<sf::Sprite> tilesClicked;
    vector<sf::Sprite> emptyTilesUnder;
    Board NewBoard(mines, rows, columns);
    numFlagsPlaced = mines;
    sf::Texture tileHiddenT = loadTexture("files/images/tile_hidden.png");
    sf::Sprite tilesHidden[tiles];
    for (int i = 0; i < tiles; ++i){tilesHidden[i].setTexture(tileHiddenT);}
    positionTileSprites(tilesHidden, tiles, tileHiddenT.getSize().x,
                        tileHiddenT.getSize().y, columns);
    sf::Texture tileRevealedT = loadTexture("files/images/tile_revealed.png");
    sf::Sprite tilesRevealed[tiles];
    sf::Sprite tileRevealed(tileRevealedT);
    for (int i = 0; i < tiles; ++i){tilesRevealed[i].setTexture(tileRevealedT);}
    positionTileSprites(tilesRevealed, tiles, tileRevealedT.getSize().x,
                        tileRevealedT.getSize().y, columns);
    sf::Texture mineT = loadTexture("files/images/mine.png");
    sf::Sprite mineS[mines];
    sf::Sprite mineSingular(mineT);
    for (int i = 0; i < mines; ++i){mineS[i].setTexture(mineT);}
    positionMineSprites(mineS, tiles, mineT.getSize().x, mineT.getSize().y, columns, NewBoard.Mines);
    sf::Sprite emptyTilesUnderMines[mines];
    for (int i = 0; i < mines;++i){emptyTilesUnderMines[i].setTexture(tileRevealedT);}
    positionMineSprites(emptyTilesUnderMines, tiles, mineT.getSize().x, mineT.getSize().y, columns, NewBoard.Mines);
    sf::Texture number1T = loadTexture("files/images/number_1.png");
    sf::Sprite number1(number1T);
    sf::Texture number2T = loadTexture("files/images/number_2.png");
    sf::Sprite number2(number2T);
    sf::Texture number3T = loadTexture("files/images/number_3.png");
    sf::Sprite number3(number3T);
    sf::Texture number4T = loadTexture("files/images/number_4.png");
    sf::Sprite number4(number4T);
    sf::Texture number5T = loadTexture("files/images/number_5.png");
    sf::Sprite number5(number5T);
    sf::Texture number6T = loadTexture("files/images/number_6.png");
    sf::Sprite number6(number6T);
    sf::Texture number7T = loadTexture("files/images/number_7.png");
    sf::Sprite number7(number7T);
    sf::Texture number8T = loadTexture("files/images/number_8.png");
    sf::Sprite number8(number8T);
    vector<sf::Sprite> Numbers{number1, number2, number3, number4, number5, number6, number7, number8};
    vector<sf::Sprite> NumberAndMines;
    positionNumberAndMines(NumberAndMines, NewBoard.NumbersMines, Numbers, mineSingular,tiles, number1T.getSize().x, number1T.getSize().y, columns);
    vector<sf::Sprite> NumbersMinesEmptyTiles;
    positionNMT(NumbersMinesEmptyTiles, NewBoard.NumbersMines, Numbers, tileRevealed, mineSingular, tiles, number1T.getSize().x, number1T.getSize().y, columns);
    sf::Texture flagT = loadTexture("files/images/flag.png");
    sf::Sprite flagSprite(flagT);
    sf::Sprite flagsWIN[mines];
    for (int i = 0; i < mines;++i){flagsWIN[i].setTexture(flagT);}
    positionMineSprites(flagsWIN, tiles, mineT.getSize().x, mineT.getSize().y, columns, NewBoard.Mines);
    sf::Texture happyFaceT = loadTexture("files/images/face_happy.png");
    sf::Sprite happyFace(happyFaceT);
    happyFace.setPosition(sf::Vector2f((((columns)/2.0)*32)-32,32*((rows)+0.5f)));
    sf::Texture winFaceT = loadTexture("files/images/face_win.png");
    sf::Sprite winFace(winFaceT);
    winFace.setPosition(sf::Vector2f((((columns)/2.0)*32)-32,32*((rows)+0.5f)));
    sf::Texture loseFaceT = loadTexture("files/images/face_lose.png");
    sf::Sprite loseFace(loseFaceT);
    loseFace.setPosition(sf::Vector2f((((columns)/2.0)*32)-32,32*((rows)+0.5f)));
    sf::Texture debugButtonT = loadTexture("files/images/debug.png");
    sf::Sprite debugButton(debugButtonT);
    debugButton.setPosition(sf::Vector2f(((columns*32)-304),32*((rows)+0.5f)));
    sf::Texture pauseButtonT = loadTexture("files/images/pause.png");
    sf::Sprite pauseButton(pauseButtonT);
    pauseButton.setPosition(sf::Vector2f(((columns*32)-240),32*((rows)+0.5f)));
    sf::Texture playButtonT = loadTexture("files/images/play.png");
    sf::Sprite playButton(playButtonT);
    playButton.setPosition(sf::Vector2f(((columns*32)-240),32*((rows)+0.5f)));
    sf::Texture leaderboardT = loadTexture("files/images/leaderboard.png");
    sf::Sprite leaderButton(leaderboardT);
    leaderButton.setPosition(((columns) * 32)-176,32*((rows)+0.5f));
    sf::Texture digitsTexture = loadTexture("files/images/digits.png");
    vector<sf::Sprite> flagCounter;
    vector<sf::Sprite> initialFlagCounter;
    vector<sf::Sprite> Timer;
    if (mines < 10){
        sf::Sprite tempSprite(digitsTexture);
        tempSprite.setTextureRect(sf::IntRect(0, 0, 21, 32));
        tempSprite.setPosition(33, 32*((rows)+0.5f)+16);
        initialFlagCounter.push_back(tempSprite);
        sf::Sprite tempSprite2(digitsTexture);
        tempSprite2.setTextureRect(sf::IntRect(0,0,21,32));
        tempSprite2.setPosition(54, 32*((rows)+0.5f)+16);
        initialFlagCounter.push_back(tempSprite2);
        sf::Sprite tempSprite3(digitsTexture);
        tempSprite3.setTextureRect(sf::IntRect(21*mines, 0, 21, 32));
        tempSprite3.setPosition(75, 32*((rows)+0.5f)+16);
        initialFlagCounter.push_back(tempSprite3);
        flagCounter = initialFlagCounter;
    }
    else if (mines >= 10 && mines < 100){
        string num_mines = to_string(mines);
        sf::Sprite tempSprite(digitsTexture);
        tempSprite.setTextureRect(sf::IntRect(0, 0, 21, 32));
        tempSprite.setPosition(33, 32*((rows)+0.5f)+16);
        initialFlagCounter.push_back(tempSprite);
        sf::Sprite tempSprite2(digitsTexture);
        int number = num_mines[0] - '0';
        tempSprite2.setTextureRect(sf::IntRect(21*number,0,21,32));
        tempSprite2.setPosition(54, 32*((rows)+0.5f)+16);
        initialFlagCounter.push_back(tempSprite2);
        number = num_mines[1] - '0';
        sf::Sprite tempSprite3(digitsTexture);
        tempSprite3.setTextureRect(sf::IntRect(21*number, 0, 21, 32));
        tempSprite3.setPosition(75, 32*((rows)+0.5f)+16);
        initialFlagCounter.push_back(tempSprite3);
        flagCounter = initialFlagCounter;
    }
    else if (mines > 99){
        string num_mines = to_string(mines);
        int number = num_mines[0] - '0';
        sf::Sprite tempSprite(digitsTexture);
        tempSprite.setTextureRect(sf::IntRect(21*number, 0, 21, 32));
        tempSprite.setPosition(33, 32*((rows)+0.5f)+16);
        initialFlagCounter.push_back(tempSprite);
        sf::Sprite tempSprite2(digitsTexture);
        number = num_mines[1] - '0';
        tempSprite2.setTextureRect(sf::IntRect(21*number,0,21,32));
        tempSprite2.setPosition(54, 32*((rows)+0.5f)+16);
        initialFlagCounter.push_back(tempSprite2);
        number = num_mines[2] - '0';
        sf::Sprite tempSprite3(digitsTexture);
        tempSprite3.setTextureRect(sf::IntRect(21*number, 0, 21, 32));
        tempSprite3.setPosition(75, 32*((rows)+0.5f)+16);
        initialFlagCounter.push_back(tempSprite3);
        flagCounter = initialFlagCounter;
    }
    sf::RenderWindow gameWindow(sf::VideoMode(width, height), "Playing Minesweeper", sf::Style::Close);
    auto start = high_resolution_clock::now();
    auto elapse = duration_cast<seconds> (high_resolution_clock::now()-start).count();
    auto pause1 = duration_cast<seconds> (high_resolution_clock::now()-start).count();
    auto pauseTime = high_resolution_clock::now();
    bool wasPaused = false;
    while (gameWindow.isOpen()){
        sf::FloatRect boardBounds(0.0f, 0.0f, (mineT.getSize().x)*columns, (mineT.getSize().y)*rows);
        gameWindow.clear(sf::Color::White);
        gameWindow.draw(happyFace);
        gameWindow.draw(debugButton);
        gameWindow.draw(leaderButton);
        sf::Event event;
        while (gameWindow.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    gameWindow.close();
                    return 0;
                case sf::Event::MouseButtonPressed:
                    if(event.mouseButton.button == sf::Mouse::Left){
                        sf::Vector2i mousePosition = sf::Mouse::getPosition(gameWindow);
                        if (mousePositionButton(leaderButton, mousePosition)){
                            pauseTime = high_resolution_clock::now();
                            LeaderOpened = !LeaderOpened;
                            if (won){
                                gameWindow.draw(winFace);
                            }
                            for (const auto & i : Timer){
                                gameWindow.draw(i);
                            }
                            for (const auto & j : flagCounter){
                                gameWindow.draw(j);
                            }
                            for (unsigned int i = 0; i< tiles;++i){
                                gameWindow.draw(tilesRevealed[i]);
                            }
                            if (pause){gameWindow.draw(playButton);}
                            if(!pause){gameWindow.draw(pauseButton);}
                            if(win){gameWindow.draw(winFace);}
                            if(loss){gameWindow.draw(loseFace);}
                            gameWindow.display();
                            vector<LeaderBoard> Players;
                            ifstream leaderFile("files/leaderboard.txt");
                            string singleline;
                            while(getline(leaderFile, singleline)){
                                istringstream stream(singleline);
                                string value;
                                while(getline(stream,value,',')){
                                    LeaderBoard PlayerEntry;
                                    PlayerEntry.Time = value;
                                    getline(stream,value, ',');
                                    PlayerEntry.User = value;
                                    Players.push_back(PlayerEntry);
                                }
                            }
                            int leaderWidth = 16*columns;
                            int leaderHeight = rows*16+50;
                            sf::RenderWindow leaderWindow(sf::VideoMode(leaderWidth, leaderHeight), "Leaderboard", sf::Style::Close);
                            string tab = "\t";
                            string leaderText = "1." + tab +Players.at(0).Time+tab+Players.at(0).User + "\n\n" +
                                                "2." + tab + Players.at(1).Time+tab+Players.at(1).User + "\n\n" +
                                                "3." + tab + Players.at(2).Time+tab+Players.at(2).User + "\n\n" +
                                                "4." + tab + Players.at(3).Time+tab+Players.at(3).User + "\n\n" +
                                                "5." + tab + Players.at(4).Time+tab+Players.at(4).User + "\n\n";
                            sf::Text LeaderContent(leaderText, font ,18);
                            LeaderContent.setStyle(sf::Text::Bold);
                            LeaderContent.setFillColor(sf::Color::White);
                            setText(LeaderContent, leaderWidth/2.0f, leaderHeight/2.0f+20);
                            sf::Text leaderTitle("LEADERBOARD", font, 20);
                            leaderTitle.setFillColor(sf::Color::White);
                            leaderTitle.setStyle(sf::Text::Bold | sf::Text::Underlined);
                            setText(leaderTitle, leaderWidth/2.0f, (leaderHeight/2.0f)-120);
                            while(leaderWindow.isOpen()){
                                sf::Event leaderEvent;
                                while(leaderWindow.pollEvent(leaderEvent)){
                                    if(leaderEvent.type == sf::Event::Closed){
                                        LeaderOpened = !LeaderOpened;
                                        leaderWindow.close();
                                        wasPaused = true;
                                        pause1 = duration_cast<seconds> (high_resolution_clock::now()-pauseTime).count();
                                    }
                                }
                                leaderWindow.clear(sf::Color::Blue);
                                leaderWindow.draw(leaderTitle);
                                leaderWindow.draw(LeaderContent);
                                leaderWindow.display();
                            }
                        }
                        else if (mousePositionButton(pauseButton, mousePosition)){
                            if(GameOver||LeaderOpened){
                                goto NoButtonsAllowed;
                            }
                            pause = !pause;
                            if (pause){
                                pauseTime = high_resolution_clock::now();
                            }
                            if (!pause){
                                wasPaused = true;
                                pause1 = duration_cast<seconds> (high_resolution_clock::now()-pauseTime).count();
                            }
                        }
                        else if(mousePositionButton(winFace, mousePosition)){
                            start = high_resolution_clock::now();
                            flagCounter = initialFlagCounter;
                            numFlagsPlaced = mines;
                            pause = false;
                            loss = false;
                            win = false;
                            won = false;
                            debug = false;
                            GameOver = false;
                            LeaderOpened = false;
                            correctFlags = 0;
                            numTilesRevealed = 0;
                            vector<sf::Sprite> restartFlagsPlaced;
                            flagsPlaced = restartFlagsPlaced;
                            vector<sf::Sprite> restartTilesClicked;
                            tilesClicked = restartTilesClicked;
                            vector<sf::Sprite> restartEmptyTilesUnder;
                            emptyTilesUnder = restartEmptyTilesUnder;

                            Board RestartBoard(mines, rows, columns);
                            NewBoard = RestartBoard;
                            auto* restartMines = new sf::Sprite[mines];
                            for (int i = 0; i < mines; ++i){restartMines[i].setTexture(mineT);}
                            positionMineSprites(restartMines, tiles, mineT.getSize().x, mineT.getSize().y, columns, NewBoard.Mines);
                            for (int i = 0; i < mines; ++i){
                                mineS[i] = restartMines[i];
                            }
                            delete[] restartMines;
                            auto* restartEmptyTilesUnderMines = new sf::Sprite[mines];
                            for (int i = 0; i < mines; ++i){restartEmptyTilesUnderMines[i].setTexture(tileRevealedT);}
                            positionMineSprites(restartEmptyTilesUnderMines, tiles, mineT.getSize().x, mineT.getSize().y, columns, NewBoard.Mines);
                            for (int i = 0; i < mines; ++i){
                                emptyTilesUnderMines[i] = restartEmptyTilesUnderMines[i];
                            }
                            delete[] restartEmptyTilesUnderMines;
                            vector<sf::Sprite> restartNumbersMinesEmptyTiles;
                            positionNMT(restartNumbersMinesEmptyTiles, NewBoard.NumbersMines,Numbers, tileRevealed, mineSingular, tiles, number1T.getSize().x, number1T.getSize().y, columns);
                            NumbersMinesEmptyTiles = restartNumbersMinesEmptyTiles;
                            auto* restartFlagsWIN = new sf::Sprite [mines];
                            for (int i = 0; i < mines; ++i){restartFlagsWIN[i].setTexture(flagT);}
                            positionMineSprites(restartFlagsWIN, tiles, mineT.getSize().x, mineT.getSize().y, columns, NewBoard.Mines);
                            for (int i = 0; i < mines; ++i){
                                flagsWIN[i] = restartFlagsWIN[i];
                            }
                            delete[] restartFlagsWIN;
                        }
                        else if (mousePositionButton(debugButton, mousePosition)){
                            if(GameOver || pause || LeaderOpened){
                                goto NoButtonsAllowed;
                            }
                            debug = !debug;
                        }
                        else if (boardBounds.contains(sf::Vector2f(mousePosition))){
                            if(GameOver || pause || LeaderOpened){
                                goto NoButtonsAllowed;
                            }
                            int tile_index = 0;
                            for (int i = 0; i < tiles; ++i){
                                if (tilesHidden[i].getGlobalBounds().contains(sf::Vector2f(mousePosition))){
                                    tile_index = i;
                                }
                            }
                            for (const auto & j : tilesClicked){
                                if (tilesHidden[tile_index].getGlobalBounds()==j.getGlobalBounds()){
                                    goto NoButtonsAllowed;
                                }
                            }
                            for (const auto & i : flagsPlaced){
                                if (tilesHidden[tile_index].getGlobalBounds()==i.getGlobalBounds()){
                                    goto NoButtonsAllowed;
                                }
                            }
                            if (NewBoard.NumbersMines.at(tile_index).mine){
                                loss = !loss;
                                GameOver = !GameOver;
                            }
                            else if(NewBoard.NumbersMines.at(tile_index).hasnumber){
                                tilesClicked.push_back(NumbersMinesEmptyTiles.at(tile_index));
                                emptyTilesUnder.push_back(tilesRevealed[tile_index]);
                                numTilesRevealed += 1;
                            }

                            else if(NewBoard.NumbersMines.at(tile_index).empty){
                                vector<sf::Sprite> TempVector = findEmptyRecursive(NewBoard.NumbersMines, NumbersMinesEmptyTiles, tile_index, rows, columns, tiles, tilesRevealed, emptyTilesUnder, flagsPlaced, tilesClicked);
                                tilesClicked.insert(tilesClicked.end(), TempVector.begin(), TempVector.end());
                                numTilesRevealed = tilesClicked.size();
                            }
                            if (numTilesRevealed == (tiles-mines)){
                                numFlagsPlaced = 0;
                                win = !win;
                                string flagsPlacedString = to_string(numFlagsPlaced);
                                if(flagsPlacedString.length() == 1){
                                    vector<sf::Sprite> tempCounterSprites;
                                    sf::Sprite tempSprite(digitsTexture);
                                    tempSprite.setTextureRect(sf::IntRect(0, 0, 21, 32));
                                    tempSprite.setPosition(33, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite);
                                    sf::Sprite tempSprite2(digitsTexture);
                                    tempSprite2.setTextureRect(sf::IntRect(0,0,21,32));
                                    tempSprite2.setPosition(54, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite2);
                                    int number = flagsPlacedString[0] - '0';
                                    sf::Sprite tempSprite3(digitsTexture);
                                    tempSprite3.setTextureRect(sf::IntRect(21*number, 0, 21, 32));
                                    tempSprite3.setPosition(75, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite3);
                                    flagCounter = tempCounterSprites;
                                }
                                won = true;
                                GameOver = !GameOver;
                            }

                        }
                    }
                    if (event.mouseButton.button == sf::Mouse::Right) {
                        if(GameOver || pause || LeaderOpened){
                            goto NoButtonsAllowed;
                        }
                        sf::Vector2i mousePos = sf::Mouse::getPosition(gameWindow);
                        if (boardBounds.contains(sf::Vector2f(mousePos))){
                            int tile_index = 0;
                            for (int i = 0; i < tiles; ++i){
                                if (tilesHidden[i].getGlobalBounds().contains(sf::Vector2f(mousePos))){
                                    tile_index = i;
                                }
                            }
                            for (const auto & j : tilesClicked){
                                if (tilesHidden[tile_index].getGlobalBounds() == j.getGlobalBounds()){
                                    goto NoButtonsAllowed;
                                }
                            }
                            if (tile_index >= 0 && tile_index <= tiles-1){
                                bool flagAlready = false;
                                for (int j = 0; j < flagsPlaced.size(); ++j){
                                    if (flagsPlaced.at(j).getGlobalBounds().contains(sf::Vector2f(mousePos))){
                                        flagsPlaced.erase(flagsPlaced.begin()+j);
                                        numFlagsPlaced += 1;
                                        flagAlready = true;
                                    }
                                }
                                if (!flagAlready){
                                    positionFlag(flagSprite, tile_index, tiles, flagT.getSize().x, flagT.getSize().y, columns);
                                    flagsPlaced.push_back(flagSprite);
                                    numFlagsPlaced -=1;
                                }
                                int tempCorrectFlags = 0;
                                for (const auto & i : flagsPlaced){
                                    for (int j = 0; j < mines; ++j){
                                        if (i.getGlobalBounds() == mineS[j].getGlobalBounds()){
                                            tempCorrectFlags +=1;
                                        }
                                    }
                                    correctFlags = tempCorrectFlags;
                                }
                                string flagsPlacedString = to_string(numFlagsPlaced);
                                if(flagsPlacedString.length() == 1){
                                    vector<sf::Sprite> tempCounterSprites;
                                    sf::Sprite tempSprite(digitsTexture);
                                    tempSprite.setTextureRect(sf::IntRect(0, 0, 21, 32));
                                    tempSprite.setPosition(33, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite);
                                    sf::Sprite tempSprite2(digitsTexture);
                                    tempSprite2.setTextureRect(sf::IntRect(0,0,21,32));
                                    tempSprite2.setPosition(54, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite2);
                                    int number = flagsPlacedString[0] - '0';
                                    sf::Sprite tempSprite3(digitsTexture);
                                    tempSprite3.setTextureRect(sf::IntRect(21*number, 0, 21, 32));
                                    tempSprite3.setPosition(75, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite3);
                                    flagCounter = tempCounterSprites;
                                }
                                else if(flagsPlacedString.length() == 2 && flagsPlacedString[0] != '-'){
                                    vector<sf::Sprite> tempCounterSprites;
                                    sf::Sprite tempSprite(digitsTexture);
                                    tempSprite.setTextureRect(sf::IntRect(0, 0, 21, 32));
                                    tempSprite.setPosition(33, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite);
                                    int number = flagsPlacedString[0] - '0';
                                    sf::Sprite tempSprite2(digitsTexture);
                                    tempSprite2.setTextureRect(sf::IntRect(21*number,0,21,32));
                                    tempSprite2.setPosition(54, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite2);
                                    number = flagsPlacedString[1] - '0';
                                    sf::Sprite tempSprite3(digitsTexture);
                                    tempSprite3.setTextureRect(sf::IntRect(21*number, 0, 21, 32));
                                    tempSprite3.setPosition(75, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite3);
                                    flagCounter = tempCounterSprites;
                                }
                                else if(flagsPlacedString.length() == 2 && flagsPlacedString[0] == '-'){
                                    vector<sf::Sprite> tempCounterSprites;
                                    sf::Sprite tempSprite(digitsTexture);
                                    tempSprite.setTextureRect(sf::IntRect(21*10, 0, 21, 32));
                                    tempSprite.setPosition(12, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite);
                                    sf::Sprite tempSprite2(digitsTexture);
                                    tempSprite2.setTextureRect(sf::IntRect(0, 0, 21, 32));
                                    tempSprite2.setPosition(33, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite2);
                                    sf::Sprite tempSprite3(digitsTexture);
                                    tempSprite3.setTextureRect(sf::IntRect(0,0,21,32));
                                    tempSprite3.setPosition(54, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite3);
                                    int number = flagsPlacedString[1] - '0';
                                    sf::Sprite tempSprite4(digitsTexture);
                                    tempSprite4.setTextureRect(sf::IntRect(21*number, 0, 21, 32));
                                    tempSprite4.setPosition(75, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite4);
                                    flagCounter = tempCounterSprites;
                                }
                                else if (flagsPlacedString.length() == 3 && flagsPlacedString[0] != '-'){
                                    vector<sf::Sprite> tempCounterSprites;
                                    int number = flagsPlacedString[0] - '0';
                                    sf::Sprite tempSprite(digitsTexture);
                                    tempSprite.setTextureRect(sf::IntRect(21*number, 0, 21, 32));
                                    tempSprite.setPosition(33, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite);
                                    number = flagsPlacedString[1] - '0';
                                    sf::Sprite tempSprite2(digitsTexture);
                                    tempSprite2.setTextureRect(sf::IntRect(21*number,0,21,32));
                                    tempSprite2.setPosition(54, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite2);
                                    number = flagsPlacedString[2] - '0';
                                    sf::Sprite tempSprite3(digitsTexture);
                                    tempSprite3.setTextureRect(sf::IntRect(21*number, 0, 21, 32));
                                    tempSprite3.setPosition(75, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite3);
                                    flagCounter = tempCounterSprites;
                                }
                                else if(flagsPlacedString.length() == 3 && flagsPlacedString[0] == '-'){
                                    vector<sf::Sprite> tempCounterSprites;
                                    sf::Sprite tempSprite(digitsTexture);
                                    tempSprite.setTextureRect(sf::IntRect(21*10, 0, 21, 32));
                                    tempSprite.setPosition(12, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite);
                                    sf::Sprite tempSprite2(digitsTexture);
                                    tempSprite2.setTextureRect(sf::IntRect(0,0,21,32));
                                    tempSprite2.setPosition(33, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite2);
                                    sf::Sprite tempSprite3(digitsTexture);
                                    int number = flagsPlacedString[1] - '0';
                                    tempSprite3.setTextureRect(sf::IntRect(21*number, 0, 21, 32));
                                    tempSprite3.setPosition(54, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite3);
                                    sf::Sprite tempSprite4(digitsTexture);
                                    number = flagsPlacedString[2] - '0';
                                    tempSprite4.setTextureRect(sf::IntRect(21*number, 0, 21, 32));
                                    tempSprite4.setPosition(75, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite4);
                                    flagCounter = tempCounterSprites;
                                }
                                else if(flagsPlacedString.length() == 4 && flagsPlacedString[0] == '-'){
                                    vector<sf::Sprite> tempCounterSprites;
                                    sf::Sprite tempSprite(digitsTexture);
                                    tempSprite.setTextureRect(sf::IntRect(21*10, 0, 21, 32));
                                    tempSprite.setPosition(12, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite);
                                    int number = flagsPlacedString[1] - '0';
                                    sf::Sprite tempSprite2(digitsTexture);
                                    tempSprite2.setTextureRect(sf::IntRect(21*number,0,21,32));
                                    tempSprite2.setPosition(33, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite2);
                                    sf::Sprite tempSprite3(digitsTexture);
                                    number = flagsPlacedString[2] - '0';
                                    tempSprite3.setTextureRect(sf::IntRect(21*number, 0, 21, 32));
                                    tempSprite3.setPosition(54, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite3);
                                    sf::Sprite tempSprite4(digitsTexture);
                                    number = flagsPlacedString[3] - '0';
                                    tempSprite4.setTextureRect(sf::IntRect(21*number, 0, 21, 32));
                                    tempSprite4.setPosition(75, 32*((rows)+0.5f)+16);
                                    tempCounterSprites.push_back(tempSprite4);
                                    flagCounter = tempCounterSprites;
                                }
                            }
                        }
                    }
            }
        }
        NoButtonsAllowed:
        elapse = duration_cast<seconds> (high_resolution_clock::now()-start).count();
        if (wasPaused) {
            elapse = elapse - pause1;
            wasPaused = !wasPaused;
            start += high_resolution_clock::now() - pauseTime;
        }
        if (!GameOver && !pause){
            float seconds = elapse;
            int num_minutes = (int)seconds/60;
            int num_seconds = (int)seconds % 60;
            string minutes = to_string(num_minutes);
            string secondsLeft = to_string(num_seconds);
            if(minutes.length() ==1){
                vector<sf::Sprite> tempTimer;
                sf::Sprite tempSprite(digitsTexture);
                tempSprite.setTextureRect(sf::IntRect(0,0,21,32));
                tempSprite.setPosition(((columns)*32)-97, 32*((rows)+0.5f)+16);
                tempTimer.push_back(tempSprite);
                int number = minutes[0] - '0';
                sf::Sprite tempSprite2(digitsTexture);
                tempSprite2.setTextureRect(sf::IntRect(21*number, 0, 21, 32));
                tempSprite2.setPosition(((columns)*32)-76, 32*((rows)+0.5f)+16);
                tempTimer.push_back(tempSprite2);
                if(secondsLeft.length() == 1){
                    sf::Sprite tempSprite3(digitsTexture);
                    tempSprite3.setTextureRect(sf::IntRect(0,0,21,32));
                    tempSprite3.setPosition(((columns)*32)-54, 32*((rows)+0.5f)+16);
                    tempTimer.push_back(tempSprite3);
                    number = secondsLeft[0] - '0';
                    sf::Sprite tempSprite4(digitsTexture);
                    tempSprite4.setTextureRect(sf::IntRect(21*number, 0, 21, 32));
                    tempSprite4.setPosition(((columns)*32)-33, 32*((rows)+0.5f)+16);
                    tempTimer.push_back(tempSprite4);
                    Timer = tempTimer;
                }
                else if(secondsLeft.length() == 2){
                    number = secondsLeft[0] - '0';
                    sf::Sprite tempSprite3(digitsTexture);
                    tempSprite3.setTextureRect(sf::IntRect(21*number,0,21,32));
                    tempSprite3.setPosition(((columns)*32)-54, 32*((rows)+0.5f)+16);
                    tempTimer.push_back(tempSprite3);
                    number = secondsLeft[1] - '0';
                    sf::Sprite tempSprite4(digitsTexture);
                    tempSprite4.setTextureRect(sf::IntRect(21*number, 0, 21, 32));
                    tempSprite4.setPosition(((columns)*32)-33, 32*((rows)+0.5f)+16);
                    tempTimer.push_back(tempSprite4);
                    Timer = tempTimer;
                }
            }
            else if(minutes.length() ==2) {
                vector<sf::Sprite> tempTimer;
                int number = minutes[0] - '0';
                sf::Sprite tempSprite(digitsTexture);
                tempSprite.setTextureRect(sf::IntRect(21 * number, 0, 21, 32));
                tempSprite.setPosition(((columns) * 32) - 97, 32 * ((rows) + 0.5f) + 16);
                tempTimer.push_back(tempSprite);
                number = minutes[1] - '0';
                sf::Sprite tempSprite2(digitsTexture);
                tempSprite2.setTextureRect(sf::IntRect(21 * number, 0, 21, 32));
                tempSprite2.setPosition(((columns) * 32) - 76, 32 * ((rows) + 0.5f) + 16);
                tempTimer.push_back(tempSprite2);
                if (secondsLeft.length() == 1) {
                    sf::Sprite tempSprite3(digitsTexture);
                    tempSprite3.setTextureRect(sf::IntRect(0, 0, 21, 32));
                    tempSprite3.setPosition(((columns) * 32) - 54, 32 * ((rows) + 0.5f) + 16);
                    tempTimer.push_back(tempSprite3);
                    number = secondsLeft[0] - '0';
                    sf::Sprite tempSprite4(digitsTexture);
                    tempSprite4.setTextureRect(sf::IntRect(21 * number, 0, 21, 32));
                    tempSprite4.setPosition(((columns) * 32) - 33, 32 * ((rows) + 0.5f) + 16);
                    tempTimer.push_back(tempSprite4);
                    Timer = tempTimer;
                }
                else if (secondsLeft.length() == 2) {
                    number = secondsLeft[0] - '0';
                    sf::Sprite tempSprite3(digitsTexture);
                    tempSprite3.setTextureRect(sf::IntRect(21 * number, 0, 21, 32));
                    tempSprite3.setPosition(((columns) * 32) - 54, 32 * ((rows) + 0.5f) + 16);
                    tempTimer.push_back(tempSprite3);
                    number = secondsLeft[1] - '0';
                    sf::Sprite tempSprite4(digitsTexture);
                    tempSprite4.setTextureRect(sf::IntRect(21 * number, 0, 21, 32));
                    tempSprite4.setPosition(((columns) * 32) - 33, 32 * ((rows) + 0.5f) + 16);
                    tempTimer.push_back(tempSprite4);
                    Timer = tempTimer;
                }
            }
        }
        for (const auto & i : Timer){
            gameWindow.draw(i);
        }
        for (const auto & i : flagCounter){
            gameWindow.draw(i);
        }
        for (unsigned int i = 0; i < tiles; ++i){
            gameWindow.draw(tilesHidden[i]);
        }
        for (const auto & i : emptyTilesUnder){
            gameWindow.draw(i);
        }
        for (const auto& i: tilesClicked){
            gameWindow.draw(i);
        }
        for (const auto & i : flagsPlaced){
            gameWindow.draw(i);
        }
        if (win){
            vector<LeaderBoard> Players;
            ifstream leaderFile1("files/leaderboard.txt");
            string singleline;
            while(getline(leaderFile1, singleline)){
                istringstream stream(singleline);
                string value;
                while(getline(stream,value,',')){
                    LeaderBoard PlayerEntry;
                    PlayerEntry.Time = value;
                    getline(stream,value, ',');
                    PlayerEntry.User = value;
                    Players.push_back(PlayerEntry);
                }
            }
            leaderFile1.close();
            float seconds = elapse;
            int num_minutes = (int) seconds / 60;
            string newRecordMinutes = to_string(num_minutes);
            int num_seconds = (int) seconds % 60;
            string newRecordSeconds = to_string(num_seconds);
            if (newRecordMinutes.length() == 1) {
                newRecordMinutes = "0" + newRecordMinutes;
            }
            if (newRecordSeconds.length() == 1) {
                newRecordSeconds = "0" + newRecordSeconds;
            }

            for (int i = 0; i < Players.size(); i++) {
                string minutesPlayer = Players.at(i).Time.substr(0, 2);
                string secondsPlayer = Players.at(i).Time.substr(3, 5);
                int min = stoi(minutesPlayer);
                int sec = stoi(secondsPlayer);
                if (num_minutes < min) {
                    string strPlayerTime = newRecordMinutes + ":" + newRecordSeconds;
                    LeaderBoard newPlayer(userName, strPlayerTime);
                    Players.insert(Players.begin() + i,newPlayer);
                    break;
                }
                else if ((num_minutes==min) && (num_seconds <= sec)){
                    string strPlayerTime = newRecordMinutes + ":" + newRecordSeconds;
                    LeaderBoard newPlayer(userName, strPlayerTime);
                    Players.insert(Players.begin() + i,newPlayer);
                    break;
                }
            }
            ofstream newLeaderBoard("files/leaderboard.txt");
            for (auto & Player : Players){
                newLeaderBoard << Player.Time << "," << Player.User<<endl;
            }
            newLeaderBoard.close();
            gameWindow.draw(pauseButton);
            for (const auto & i : flagCounter){
                gameWindow.draw(i);
            }
            for (const auto & i : Timer){
                gameWindow.draw(i);
            }
            for (unsigned int i = 0; i < tiles; ++i){
                gameWindow.draw(tilesHidden[i]);
            }
            for (const auto & i : flagsPlaced){
                gameWindow.draw(i);
            }
            for (const auto & i : emptyTilesUnder){
                gameWindow.draw(i);
            }
            for (const auto& i: tilesClicked){
                gameWindow.draw(i);
            }
            for(int i = 0; i < mines; ++i){
                gameWindow.draw(flagsWIN[i]);
            }
            gameWindow.draw(winFace);
            if(debug){
                for (unsigned int i = 0; i < mines; ++i){
                    gameWindow.draw(mineS[i]);
                }
            }
            for (const auto & i : flagsPlaced){
                gameWindow.draw(i);
            }
            gameWindow.draw(winFace);
            for(int i = 0; i < mines; ++i){
                gameWindow.draw(flagsWIN[i]);
            }
            gameWindow.display();
            LeaderOpened = !LeaderOpened;
            vector<LeaderBoard> Players2;
            ifstream leaderFile("files/leaderboard.txt");
            string singleLine;
            while(getline(leaderFile, singleLine)){
                istringstream stream(singleLine);
                string value;
                while(getline(stream,value,',')){
                    LeaderBoard PlayerEntry;
                    PlayerEntry.Time = value;
                    getline(stream,value, ',');
                    PlayerEntry.User = value;
                    Players2.push_back(PlayerEntry);
                }
            }
            int leaderWidth = 16*columns;
            int leaderHeight = rows*16+50;
            sf::RenderWindow leaderWindow(sf::VideoMode(leaderWidth, leaderHeight), "Leaderboard", sf::Style::Close);
            string tab = "\t";
            string leaderText = "1." + tab +Players2.at(0).Time+tab+Players2.at(0).User + "\n\n" +
                                "2." + tab + Players2.at(1).Time+tab+Players2.at(1).User + "\n\n" +
                                "3." + tab + Players2.at(2).Time+tab+Players2.at(2).User + "\n\n" +
                                "4." + tab + Players2.at(3).Time+tab+Players2.at(3).User + "\n\n" +
                                "5." + tab + Players2.at(4).Time+tab+Players2.at(4).User + "\n\n";
            sf::Text LeaderContent(leaderText, font ,18);
            LeaderContent.setStyle(sf::Text::Bold);
            LeaderContent.setFillColor(sf::Color::White);
            setText(LeaderContent, leaderWidth/2.0f, leaderHeight/2.0f+20);
            sf::Text leaderTitle("LEADERBOARD", font, 20);
            leaderTitle.setFillColor(sf::Color::White);
            leaderTitle.setStyle(sf::Text::Bold | sf::Text::Underlined);
            setText(leaderTitle, leaderWidth/2.0f, (leaderHeight/2.0f)-120);
            while(leaderWindow.isOpen()){
                sf::Event leaderEvent2;
                while(leaderWindow.pollEvent(leaderEvent2)){
                    if(leaderEvent2.type == sf::Event::Closed){
                        LeaderOpened = !LeaderOpened;
                        leaderWindow.close();
                        win = !win;
                    }
                }
                leaderWindow.clear(sf::Color::Blue);
                leaderWindow.draw(leaderTitle);
                leaderWindow.draw(LeaderContent);
                leaderWindow.display();
            }

        }
        if (won){
            gameWindow.draw(winFace);
            for(int i = 0; i < mines; ++i){
                gameWindow.draw(flagsWIN[i]);
            }
        }
        if (loss){
            gameWindow.draw(loseFace);
            for(unsigned int i = 0; i< mines; ++i){
                gameWindow.draw(emptyTilesUnderMines[i]);
            }
            for (const auto & i : flagsPlaced){
                gameWindow.draw(i);
            }
            for (unsigned int i = 0; i < mines; ++i){
                gameWindow.draw(mineS[i]);
            }
        }
        if(debug){
            for (unsigned int i = 0; i < mines; ++i){
                gameWindow.draw(mineS[i]);
            }
            if(won){
                for(int i = 0; i < mines; ++i){
                    gameWindow.draw(flagsWIN[i]);
                }
            }
        }
        if (pause){
            gameWindow.draw(playButton);
            for (unsigned int i = 0; i< tiles;++i){
                gameWindow.draw(tilesRevealed[i]);
            }
        }
        else {
            gameWindow.draw(pauseButton);
        }
        gameWindow.display();

    }
    return 0;
}
