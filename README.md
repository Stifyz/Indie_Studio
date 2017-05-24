# Indie Studio: Gauntlet

Ce fichier sera mis à jour progressivement, j'essaierais de vous dire quand ça sera le cas.

Il sera une source d'information au même titre que Discord.

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

## Norme commune

### Règles de nommage

- **Namespace**: camelCase
- **Fonction**: camelCase
- **Classe**: PascalCase
- **Enum**: PascalCase
- **Variable**: camelCase
  - **Variables static privées**: s_camelCase
  - **Variables membres privés**: m_camelCase (ex: `m_name`, `m_isBroken`)
- **Getters**: nomDeLaVariable (ex: `name`, `isBroken`)
- **Setters**: setNomDeLaVariable (ex: `setName`, `setBrokenState`)

### Règles générales

- Espaces entre opérateurs (ex: `a + b`)
- **JAMAIS** de tabulation entre le type et le nom d'une fonction/variable, un espace suffit
- Indicateur de pointeur/référence sur le nom (ex: `int &a, char *b`)
- Interdiction de `#pragma once`
- Toujours utiliser `override` quand on remplace une méthode virtuelle
- Toujours utiliser le `for-range` au lieu du `for` standard quand c'est possible

Exemples de `for-range`:

```cpp
void someFunc() {
	std::vector<int> myVec{0, 1, 2, 3};
	for (int i : myVec) {
		std::cout << i << std::endl;
	}
}
```

```cpp
void someOtherFunc() {
	std::array<std::string, 5> myArray = {
		"hello", "world", "foo", "bar", "baz"
	};

	for (const std::string &str : myArray) {
		std::cout << str << std::endl;
	}
}
```

### Règles d'indentation/alignement

- Je vous conseille d'afficher vos tabulations pour les distinguer plus facilement des espaces. :)
- L'indentation se fait avec des **TABULATIONS**
- L'alignement se fait avec des **ESPACES**
- Jamais d'espace/tab en fin de ligne

Par exemple:

```cpp
int add(int a,
        int &b) {
	return a + b;
}
```

- Déjà faire ça c'est moche, mais passons.
  - Sur la ligne 2, uniquement des espaces
    - Si j'avais mis des tabulations l'alignement n'aurait pas été préservé vu qu'il n'y en a pas dans la ligne 1
  - Sur la ligne 3, une tabulation, comme d'hab et c'est tout

Un autre exemple:

```cpp
void SomeObject::someFunction(const SomeOtherObject &someOtherObject) {
	someOtherObject.callToSomeFunctionWithALongName("a super long string",
	                                                21039);
}
```

- Voilà un cas plus réaliste déjà.
  - Sur la ligne 2, une tabulation, normal
  - Sur la ligne 3, une tabulation pour matcher celle de la ligne 2, puis des espaces pour atteindre la hauteur du premier argument

### Règles de construction des classes

- Ne mettez les parties `public`, `protected` ou `private` que si nécessaire !
- Utilisez `= default` et `= delete` dès que possible

```cpp
class Name {
	public:
		Name();

	protected:
		/* something here */

	private:
		int m_a = 5;                      /* C++11 feature */

		SomeObject m_object{"param1", 2}; /* C++11 too */
};
```
## Features C++ à connaître et à utiliser

- Constructeur par déplacement (ex: `Truc(Truc &&)`)
- Pointeurs intelligents (`std::unique_ptr`, `std::shared_ptr`)
- `std::function` + lambdas
- `std::initializer_list`
  - Surtout utile pour passer un tableau en paramètre à une fonction (ex: `myFunc("truc", {1, 23, 21}, 23)`)
  - Cette syntaxe d'appel de fonction fonctionne aussi avec d'autres conteneurs comme `std::vector`

