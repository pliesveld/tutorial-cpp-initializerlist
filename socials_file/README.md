Organization of Components
====

## _How to store a set of attributes of a common type, that may vary slightly_

Following example taken from the [Rom2.4 source code](https://github.com/avinson/rom24-quickmud/blob/master/src/)

## In Rom2.4

 
 #### Some socials cannot target others.  Hence in the type below, some fields may be null: 
 
```
struct    social_type
{
    char      name[20];
    char *    char_no_arg;
    char *    others_no_arg;
    char *    char_found;
    char *    others_found;
    char *    vict_found;
    char *    char_not_found;
    char *    char_auto;
    char *    others_auto;
};
```

[structure for a social in the socials table](https://github.com/avinson/rom24-quickmud/blob/master/src/merc.h#L2152)


#### On initialization, socials are loaded from a flat file.  When parsing from a file, when a social does not have al the fields, then a special character denotes the end of the current social being read.

[load_socials](https://github.com/avinson/rom24-quickmud/blob/master/src/db2.c#L53)

```
struct social_type social_table[MAX_SOCIALS];
int social_count;



void load_socials (FILE * fp)
{
    for (;;)
    {
        struct social_type social;
        char *temp;
        /* clear social */
        social.char_no_arg = NULL;
        social.others_no_arg = NULL;
        social.char_found = NULL;
        social.others_found = NULL;
        social.vict_found = NULL;
        social.char_not_found = NULL;
        social.char_auto = NULL;
        social.others_auto = NULL;

        temp = fread_word (fp);
        if (!strcmp (temp, "#0"))
            return;                /* done */
#if defined(social_debug)
        else
            fprintf (stderr, "%s\n\r", temp);
#endif

        strcpy (social.name, temp);
        fread_to_eol (fp);

        temp = fread_string_eol (fp);
        if (!strcmp (temp, "$"))
            social.char_no_arg = NULL;
        else if (!strcmp (temp, "#"))
        {
            social_table[social_count] = social;
            social_count++;
            continue;
        }

        ...

```


## Flat file 

###### The socials are loaded from disk.  Below is a snippet of how socials are organized in the file:  

```
...


snore 0 0
Zzzzzzzzzzzzzzzzz.
$n snores loudly.
#

squeeze 0 0
Where, what, how, WHO ???
$
You squeeze $M fondly.
$n squeezes $N fondly.
$n squeezes you fondly.
Where, what, how, WHO ???
You squeeze yourself - try to relax a little!
$n squeezes $mself.

...

```

[social.are](https://github.com/avinson/rom24-quickmud/blob/master/area/social.are#L528)

