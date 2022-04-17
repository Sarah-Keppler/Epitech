/*
** EPITECH PROJECT, 2021
** Arcade_2020
** File description:
** Core
*/

#include "Core.hpp"
#include <iostream>

Arcade::Core::Core(int const ac, char ** const av) : _run(true), _menu(true), _cgraph(0), _cgame(0)
{
    if (ac != 2)
        throw FatalError("Invalid number of arguments");

    Arcade::ILib *lib;
    std::string name = av[1];
    std::string tmp;
    std::size_t pos = name.find_last_of("/");
    std::vector<std::string> a = _loader.getLibrariesPath();
    std::vector<std::string>::const_iterator i = a.begin();

    lib = _loader.getInstance(name, "endPoint");
    if (!i->compare(name) && lib->getType() != Arcade::Type::GRAPH)
        throw FatalError("Invalid type");
    _graphs.push_back(static_cast<Graph::AGraph *>(lib));
    if (pos != std::string::npos)
        name = name.substr(pos);
    for (; i != a.end(); ++i) {
        pos = i->find_last_of("/");
        if (pos != std::string::npos)
            tmp = i->substr(pos);
        if (!tmp.compare(name)) {
            continue;
        }
        lib = _loader.getInstance(*i, "endPoint");
        if (lib->getType() == Arcade::Type::GRAPH)
            _graphs.push_back(static_cast<Graph::AGraph *>(lib));
        if (lib->getType() == Arcade::Type::GAME) {
            _games.push_back(static_cast<Game::AGame *>(lib));
            _scores.init(_games.back()->getName());
        }
    }
    _scoreboard = _scores.getScores();
    if (_graphs.empty() || _games.empty())
        throw FatalError("Core: Not enough games or graphics libraries");
    initNames();
    for (std::size_t i = 0; _Ngraphs.size() > i; ++i)
	if (!_Ngraphs[i].compare(name))
	    _cgraph = i;
}

void Arcade::Core::initNames(void)
{
std::vector<Graph::AGraph *>::const_iterator i = _graphs.begin();
std::vector<Game::AGame *>::const_iterator e = _games.begin();

    for (; i != _graphs.end(); ++i)
        _Ngraphs.push_back((*i)->getName());
    for (; e != _games.end(); ++e)
        _Ngames.push_back((*e)->getName());
}

Arcade::Core::~Core()
{
}

void Arcade::Core::changeGraph(std::string const &graph)
{
std::vector<Graph::AGraph *>::const_iterator i = _graphs.begin();

    for (; i != _graphs.end(); ++i) {
        if (!graph.compare((*i)->getName())) {
            _cgame = i - _graphs.begin();
            return;
    }
}
throw MinorError("Core: \"" + graph + "\": unknown game");
}

void Arcade::Core::changeGame(std::string const &game)
{
    std::vector<Game::AGame *>::const_iterator i = _games.begin();

    for (; i != _games.end(); ++i) {
        if (!game.compare((*i)->getName())) {
            _cgame = i - _games.begin();
            return;
    }
}
throw MinorError("Core: \"" + game + "\": unknown game");
}

void Arcade::Core::handleLibEvents(Arcade::Events const evt)
{
    if (evt == Arcade::Events::NEXT_GAME)
        _cgame = (_cgame >= _games.size()) ? 0 : _cgame + 1;
    else if (evt == Arcade::Events::PREV_GAME)
        _cgame = (!_cgame) ? _games.size() - 1 : _cgame - 1;
    else if (evt == Arcade::Events::NEXT_LIB)
        _cgraph = (_cgraph >= _graphs.size()) ? 0 : _cgraph + 1;
    else if (evt == Arcade::Events::PREV_LIB)
        _cgraph = (!_cgraph) ? _graphs.size() - 1 : _cgraph - 1;
}

void Arcade::Core::handleCoreEvents(Arcade::Events const evt)
{
    if (_menu) {
        if (Arcade::Events::NEXT_GAME == evt)
            changeGame("name");
        if (Arcade::Events::NEXT_LIB == evt)
            changeGraph("graph");
    } else {
        handleLibEvents(evt);
    }
    if (Arcade::Events::QUIT == evt)
        _run = false;
    if (Arcade::Events::MENU == evt) {
        _games[_cgame]->load(_graphs[_cgraph]);
        _menu = false;
    }
}

void Arcade::Core::run(void)
{
    std::chrono::_V2::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapse = std::chrono::steady_clock::now() - begin;
    Game::Menu _Menu(_Ngraphs, _Ngames, _scoreboard);

    for (std::string str : _Ngraphs)
    for (std::vector<Graph::AGraph *>::iterator it = _graphs.begin(), et = _graphs.end(); et != it; ++it)
	std::cout << (*it)->getName() << std::endl;
    std::cout << _cgraph << std::endl;
    try {
        _graphs[_cgraph]->open("Arcade", "Ressources/wallpaper.png");
        _Menu.load(_graphs[_cgraph]);
        Arcade::Events evt = _Menu.handleEvents();
        while (_run) {
                if (_menu) {
                evt = _Menu.handleEvents();
                handleCoreEvents(evt);
                elapse = std::chrono::steady_clock::now() - begin;
                _Menu.handleUpdate(elapse.count());
                _Menu.display();
            } else {
                evt = _games[_cgame]->handleEvents();
                handleCoreEvents(evt);
                elapse = std::chrono::steady_clock::now() - begin;
                _games[_cgame]->handleUpdate(elapse.count());
            }
        }
    } catch (Arcade::Error const &err)
    {
	std::cerr << err.what() << std::endl;
    }
}
