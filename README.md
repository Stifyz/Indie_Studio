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

OK alors on a plusieurs problèmes.

- Je vais devoir repenser 100% de mon archi vu qu'on utilise un engine, je sais même pas pourquoi j'y ai pas pensé avant
- Il y a un **ÉNORME** travail sur les assets. Je m'explique : Ogre3D utilise son propre format de mesh, du coup il faut utiliser blender2ogre 0.6.2 pour convertir des fichiers Blender en fichiers Mesh Ogre3D et c'est pas super pratique.
- J'ai **VRAIMENT** besoin de vous les gars. Si vous voulez pas bosser on drop le projet et on se prend tous un grade D/Échec au module hein. Il nous reste à peine deux semaines et on a... rien du tout. Mais genre vraiment rien du tout.

Du coup j'ai essayé de repenser la répartion des tâches (c'est la dernière fois, j'vous jure).

- **Bazin:** Ogre3D, Procédural
- **Zimmer:** Ogre3D, Procédural
- **Bunel:** Ogre3D, Game Design, Assets
- **Boubou:** Ogre3D, Assets, UI
- **Loris:** Ogre3D, Assets, UI
- **Maison:** Ogre3D, Game Design, Réseau
- **Da-sil:** Ogre3D, Game Design, Réseau
- **Syp:** Ogre3D, Game Design, Réseau

Je m'explique un peu sur les changements. On va avoir besoin que **tout le monde** se renseigne en pronfondeur sur Ogre. Je sais pas encore comment je vais réussir à architecturer le bordel, mais quoi qu'il en soit, il faut que vous puissiez tous compiler le projet et comprendre comment il fonctionne.

J'ai viré la partie ECS vu que l'engine.. bah c'est Ogre. Je pense pas que c'est totalement mort pour l'ECS, mais ça risque de me prendre du temps de trouver une nouvelle archi donc autant pas compter dessus tout de suite et prévoir un filet de sécurité.

Notes spéciales:
- À tous ceux qui vont bosser sur Ogre3D, utilisez la version 1.10, c'est la dernière version stable. Par contre je vous conseille de la compiler depuis les sources que vous pouvez trouver sur bitbucket.
- Théo, Steven, Maxime, je vous laisse uniquement le Réseau en terme de code, je compte sur vous pour ça.
- Loris, concentre toi vraiment sur les Assets, et on va en avoir besoin très très vite. Envoie un message sur Discord quand t'es chaud et je te dis ce dont j'aurais besoin.
- Boubou, regarde comment faire un menu tout simple avec Ogre3D 1.10 et fais une page de wiki pour expliquer ça, ensuite faudra l'intégrer au jeu, faire un menu principal, un menu pause, etc.. et ensuite faudra faire le HUD

***

- **Assets:** Récolter modèles 3D, textures, images, sons, musiques, etc... et faire une page de wiki par catégorie comme expliqué dans le sommaire.
- **Ogre3D:** Apprentissage de l'engine et application au projet
- **Game Design:** Rédaction d'un document détaillant les règles du jeu, les items, les entités, etc...
- **Inputs:** Gestion des entrées clavier/souris/joystick
- **Procédural:** Génération procédurale de maps / donjons
- **Réseau:** Faire communiquer des programmes à travers le réseau
- **UI:** Création des menus, du HUD, du tchat, etc..

