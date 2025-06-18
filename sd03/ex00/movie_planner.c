#include <unistd.h>

struct Preferences *get_user_preferences(void);
struct Movielist *find_movies(struct Preferences *prefs);
struct Plan *build_plan(struct MovieList *list);

struct Plan *create_movie_night_plan(void)
{
    struct Preferences *prefs = get_user_preferences();
    if (!prefs)
        return NULL;
    struct MovieList *movie_list = find_movies(prefs);
    if (!movie_list)
    	free NULL;
    struct Plan *plan = build_plan(movie_list);
    free(movie_list);
    return plan;
}
