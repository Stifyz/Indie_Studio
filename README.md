# Indie Studio: Gauntlet

Ce fichier sera mis à jour progressivement, j'essaierais de vous dire quand ça sera le cas. N'oubliez pas de regarder le [wiki](http://git.gnidmoo.tk/gnidmoo/cpp_indie_studio/wiki) qui contient d'autres informations essentielles.

Ce fichier et le wiki seront une source d'information au même titre que Discord.

## Informations générales

- Jeu sélectionné: **Gauntlet**
- Communication via Discord
- Multiplayer, avec la possibilité de jouer à plusieurs sur la même machine
- Bibliothèques utilisées:
  - Ogre3D 1.10

## Répartition des tâches

**Note:** Il y a un **ÉNORME** travail sur les assets. Je m'explique : Ogre3D utilise son propre format de mesh, du coup il faut utiliser blender2ogre 0.6.2 pour convertir des fichiers Blender en fichiers Mesh Ogre3D et c'est pas super pratique.

- **Bazin:** Ogre3D, Engine, Procédural
- **Zimmer:** Ogre3D, Engine, Procédural
- **Bunel:** Ogre3D, Game Design, Assets
- **Boubou:** Ogre3D, Assets, UI
- **Loris:** Ogre3D, Assets, UI
- **Maison:** Ogre3D, Game Design, Réseau
- **Da-sil:** Ogre3D, Game Design, Réseau
- **Syp:** Ogre3D, Game Design, Assets

Je m'explique un peu sur les changements. On va avoir besoin que **tout le monde** se renseigne en pronfondeur sur Ogre. Je sais pas encore comment je vais réussir à architecturer le bordel, mais quoi qu'il en soit, il faut que vous puissiez tous compiler le projet et comprendre comment il fonctionne.

Notes spéciales:
- Utilisez Ogre3D 1.10, c'est la dernière version stable.
- Loris, concentre toi vraiment sur les Assets, et on va en avoir besoin très très vite. Envoie un message sur Discord quand t'es chaud et je te dis ce dont j'aurais besoin.
- Boubou, regarde comment faire un menu tout simple avec Ogre3D 1.10 et fais une page de wiki pour expliquer ça, ensuite faudra l'intégrer au jeu, faire un menu principal, un menu pause, etc.. ensuite faudra faire le HUD et le tchat

***

- **Assets:** Récolter modèles 3D, textures, images, sons, musiques, etc... et faire une page de wiki par catégorie comme expliqué dans le sommaire.
- **Ogre3D:** Apprentissage de l'engine et application au projet
- **Game Design:** Rédaction d'un document détaillant les règles du jeu, les items, les entités, etc...
- **Inputs:** Gestion des entrées clavier/souris/joystick
- **Procédural:** Génération procédurale de maps / donjons
- **Réseau:** Faire communiquer des programmes à travers le réseau
- **UI:** Création des menus, du HUD, du tchat, etc..

