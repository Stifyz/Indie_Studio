# Indie Studio: Gauntlet

Ce fichier sera mis à jour progressivement, j'essaierais de vous dire quand ça sera le cas. N'oubliez pas de regarder le [wiki](http://git.gnidmoo.tk/gnidmoo/cpp_indie_studio/wiki) qui contient d'autres informations essentielles.

Ce fichier et le wiki seront une source d'information au même titre que Discord.

## Informations générales

- Jeu sélectionné: **Gauntlet**
- Communication via Discord
- Multiplayer, avec la possibilité de jouer à plusieurs sur la même machine
- Bibliothèques utilisées:
  - Irrlicht
  - Bullet (peut-être, si nécessaire)

## Répartition des tâches

**NOTE:** Une petite modification de la répartition des tâches s'impose. J'ai décidé de supprimer la partie sur Irrlicht qui n'a plus aucun sens vu que j'ai commencé à m'en occuper et que je vais finir. J'ai aussi créé une nouvelle partie Game Design.

La partie sur le Game Design est ultra importante. Le but étant de rédiger un document qui servira de référence quand on attaquera la partie Gameplay.

- **Bazin:** ECS, Procédural
- **Bunel:** Game Design, Assets, UI
- **Boubou:** Game Design, Assets, UI
- **Da-sil:** Game Design, Réseau
- **Loris:** Game Design, Assets, Inputs
- **Maison:** Game Design, Réseau
- **Syp:** Game Design, Réseau
- **Zimmer:** ECS, Procédural

Tout le monde bossera sur la partie Gameplay, sauf urgence sur une autre partie.

- **Assets:** Récolter modèles 3D, textures, images, sons, musiques, etc... et faire une page de wiki par catégorie comme expliqué dans le sommaire.
- **ECS:** Implémentation du système de gestion des entités
- **Game Design:** Rédaction d'un document détaillant les règles du jeu, les items, les entités, etc...
- **Gameplay:** Application du Game Design
- **Inputs:** Gestion des entrées clavier/souris/joystick
- **Procédural:** Génération procédurale de maps / donjons
- **Réseau:** Faire communiquer des programmes à travers le réseau
- **UI:** Création des menus, du HUD, du tchat, etc..

