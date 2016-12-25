#include "song.h"

song::song(string t, string a, int v)
{
    title = t;
    artist = a;
    view_count = v;
}

song::~song()
{
    
}

int song::return_views()
{
    return view_count;
}

void song::increase_views()
{
    view_count++;
}

string song::return_title()
{
    return title;
}

string song::return_artist()
{
    return artist;
}
