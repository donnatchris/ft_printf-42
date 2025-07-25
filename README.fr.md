##### [🇫🇷 Version française](README.fr.md) / [🇬🇧 English version](README.md)

# PROJET FT_PRINTF POUR 42
Par chdonnat (Christophe Donnat de 42 Perpignan, France)


## BUT DU PROJET
Vous allez découvrir une fonction C populaire et polyvalente : printf(). Cet exercice est une excellente
opportunité d'améliorer vos compétences en programmation. Il est d'une difficulté modérée.
Vous découvrirez les fonctions variadiques en C.
La clé d'un ft_printf réussi est un code bien structuré et extensible.

Vous devez recoder la fonction printf() de la libc.
Le prototype de ft_printf() est :
int ft_printf(const char *, ...);
Voici les exigences :
• N'implémentez pas la gestion du tampon de la fonction printf() originale.
• Votre fonction doit gérer les conversions suivantes : cspdiuxX%
• Votre fonction sera comparée à la fonction printf() originale.
• Vous devez utiliser la commande ar pour créer votre bibliothèque.
L'utilisation de la commande libtool est interdite.
• Votre libftprintf.a doit être créée à la racine de votre dépôt

Vous devez implémenter les conversions suivantes :
• %c Affiche un seul caractère.
• %s Affiche une chaîne de caractères (telle que définie par la convention C commune).
• %p L'argument pointeur void * doit être affiché au format hexadécimal.
• %d Affiche un nombre décimal (base 10).
• %i Affiche un entier en base 10.
• %u Affiche un nombre décimal non signé (base 10).
• %x Affiche un nombre au format hexadécimal (base 16) en minuscules.
• %X Affiche un nombre au format hexadécimal (base 16) en majuscules.
• %% Affiche un signe de pourcentage.

## BONUS

Vous n'êtes pas obligé de faire tous les bonus.
Liste des bonus :
• Gérer toute combinaison des flags suivants : ’-0.’ et la largeur de champ minimale
pour toutes les conversions.
• Gérer tous les flags suivants : ’# +’ (Oui, l'un d'eux est un espace)

**Note :** Je n'ai pas réalisé la partie bonus pour ce projet.

## DOCUMENTATION

### Fonctions variadiques
Les fonctions variadiques sont des fonctions en programmation qui peuvent accepter un nombre variable d'arguments.
Cela vous permet d'écrire des fonctions qui ne nécessitent pas de définir un nombre fixe de paramètres à l'avance.
Dans des langages comme le C, les fonctions variadiques sont généralement implémentées à l'aide de la bibliothèque stdarg.h, qui fournit des macros pour gérer les arguments.

Pour définir une fonction variadique en C, vous utilisez des points de suspension (...) dans la liste des paramètres de la fonction pour indiquer que la fonction peut accepter des arguments supplémentaires.
Par exemple, la fonction de la bibliothèque standard printf est variadique, car elle accepte un nombre variable d'arguments en fonction de la chaîne de format.

À l'intérieur de la fonction, les macros de stdarg.h (va_start, va_arg et va_end) sont utilisées pour accéder aux arguments variables.
- **va_start** initialise la liste d'arguments
- **va_arg** récupère chaque argument
- **va_end** nettoie la liste après le traitement.

Les fonctions variadiques sont particulièrement utiles lorsque vous ne connaissez pas le nombre d'arguments au moment de la compilation, ce qui les rend idéales pour des situations comme la mise en forme de sortie ou la gestion d'entrées utilisateur où le nombre d'éléments peut varier. Cependant, il faut être prudent lors de leur utilisation, car il n'y a pas de sécurité de type intégrée ni de validation d'arguments, ce qui peut entraîner des erreurs si le nombre d'arguments ne correspond pas aux attentes de la fonction.

### va_list:
C'est un type qui contient les informations nécessaires pour accéder aux arguments variables.
C'est essentiellement un pointeur qui sera utilisé pour parcourir la liste des arguments passés à la fonction variadique.

### va_start:
Cette macro initialise la variable va_list. Vous appelez va_start avec deux arguments :
- la variable va_list (par exemple, args)
- et le dernier argument fixe connu avant le début des arguments variadiques.

Cette macro met en place la structure interne nécessaire pour accéder aux arguments variadiques.

### va_arg:
Une fois la va_list initialisée, vous utilisez la macro va_arg pour accéder à chaque argument individuel.
Vous passez la va_list comme premier argument à va_arg, et vous spécifiez également le type de l'argument que vous souhaitez récupérer
(puisque le compilateur ne connaît pas le type des arguments variadiques). Chaque appel à va_arg récupère l'argument suivant dans la liste.

### va_end:
Après que tous les arguments variadiques ont été traités, vous devez appeler va_end pour nettoyer.
Cette macro est utilisée pour effectuer tout nettoyage nécessaire lié à la va_list. Il est important de toujours appeler va_end pour éviter les fuites de mémoire ou de ressources.
