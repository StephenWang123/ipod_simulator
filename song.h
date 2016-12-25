#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class song
{
    
private:
    string title;
    string artist;
    int view_count;
    
public:
    song(string t, string a, int v);
   ~song();
   void increase_views();
   int return_views();
   string return_title();
   string return_artist();
    
};

#endif
