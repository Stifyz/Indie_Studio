# Indie Studio: Gauntlet

Ce fichier sera mis à jour progressivement, j'essaierais de vous dire quand ça sera le cas. N'oubliez pas de regarder le [wiki](http://git.gnidmoo.tk/gnidmoo/cpp_indie_studio/wiki) qui contient d'autres informations essentielles.

Ce fichier sera une source d'information au même titre que Discord.

## Informations générales

- Jeu sélectionné: Gauntlet
- Communication via discord
- Multiplayer, avec la possibilité de jouer sur la même machine
- Irrlicht + Bullet

## Répartition des tâches

### Partie 1

- **Irrlicht**: Boubou, Syp, Bunel
- **Reseau**: Maison, Loris, Da-sil
- **ECS**: Zimmer, Bazin

### Partie 2

- **Gameplay**: Tout le monde
- **Inputs**: Boubou
- **Procédural**: Zimmer, Bazin
- **UI**: Bunel
- **Assets**: Loris

## Features C++ à connaître et à utiliser

- Constructeur par déplacement (ex: `Truc(Truc &&)`)
- Pointeurs intelligents (`std::unique_ptr`, `std::shared_ptr`)
- `std::function` + lambdas
- `std::initializer_list`
  - Surtout utile pour passer un tableau en paramètre à une fonction (ex: `myFunc("truc", {1, 23, 21}, 23)`)
  - Cette syntaxe d'appel de fonction fonctionne aussi avec d'autres conteneurs comme `std::vector`

