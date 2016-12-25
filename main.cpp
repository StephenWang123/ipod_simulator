#include "song.h"

void view_songs(vector<song> list)
{
    vector<song>::iterator i;
    int counter = 0;
    
    
    cout << endl;
    for(i = list.begin(); i != list.end(); i++)
    {
        counter++;
        cout << counter << ". " << '"' <<(*i).return_title() << '"'
             << " by " << (*i).return_artist() << endl;
    }
}


void add_song(vector<song> &list)
{
    
    vector<song>::iterator i;
    i = list.begin();
    
    string name;
    string author;
    
    cout << '\n' << "Enter song name: ";
    getline(cin, name);
    cout << "Enter artist name: ";
    getline(cin, author);
    song temp(name, author, 0);
    i = list.insert(i, temp); 
    
}

void play_song(vector<song> &list)
{
    
    vector<song>::iterator i;
    string choice;
    view_songs(list);
    cout << endl;
    cout << "Enter name of song to play: ";
    getline(cin, choice);
    
    for(i = list.begin(); i < list.end(); i++)
    {
        if((*i).return_title() == choice)
        {
            (*i).increase_views(); 
            cout << '\n' << "Playing: " << '"' <<(*i).return_title() << '"'
             << " by " << (*i).return_artist() << "... Done" << endl;
            break;
        }
    }
    
    if (i == list.end())
        cout << '\n' << "Selected song isn't in library." << endl;
}

void shuffle(vector<song> &list)
{
    
    int j;
    vector<song>::iterator i = list.begin();
    srand(time(NULL));
    int random_index = rand() % list.size();
    
    for(j = 0; j < random_index; j++)
        i++;
        
    (*i).increase_views(); 
    cout << '\n' << "Playing: " << '"' <<(*i).return_title() << '"'
    << " by " << (*i).return_artist() << "... Done" << endl;
           
        
}

void view_statistics(vector<song> list)
{
    int max = 0;
    song temp("temp", "temp", -1);
    
    vector<song>::iterator i;
    for(i = list.begin(); i < list.end(); i++)
    {
        if ((*i).return_views() > max)
        {
            max = (*i).return_views();
            temp = (*i);
        }
    }
    
    if (max == 0)
        cout << '\n' << "You haven't listened to any songs yet!" << endl;
    else
    {
        cout << '\n' << "Most frequently listened song: " << temp.return_title() 
         << ", " << max << " times." << endl;
    }
}

void save(vector<song> list)
{
    ofstream outPut;
    outPut.open("songs.txt");
    
    vector<song>::iterator i;
    for(i = list.begin(); i < list.end(); i++)
    {
      outPut << (*i).return_title() << ';' 
             << (*i).return_artist() << ';'
             << (*i).return_views() <<  ';' << endl;
    }
    
    outPut.close();
    cout << '\n' << "Saving... Done" << endl;
}

void load(vector<song> &list)
{
    ifstream data("songs.txt");
    string token;
    string line;
    string title;
    string artist;
    string count;
    int view_count;
    
    while(getline(data, line))
    {
        int pos = 0;
        int i = 0;
        while ((pos = line.find(";")) != string::npos) 
        {
            token = line.substr(0, pos);
            line.erase(0, pos + 1);
            
            switch(i)
            {
                case 0: title = token; i++; break;
                case 1: artist = token; i++; break;
                case 2: count = token; view_count = stoi(count); i++; break;
                default: break;
            }
        }
        
        song temp(title, artist, view_count);
        vector<song>::iterator ite;
        ite = list.end();
        ite = list.insert(ite, temp); 
    }
    
}

void pause()
{
    cout << endl;
    cout << "Press enter to continue...";
    cin.ignore();
}

void main_menu()
{

  cout << endl;
  cout << "Main Menu:" << endl;
  cout << "1. View songs" << endl;
  cout << "2. Add song to library" << endl;
  cout << "3. Play a song" << endl;
  cout << "4. Shuffle" << endl;
  cout << "5. View statistics" << endl;
  cout << "6. Save" << endl;
  cout << "7. Exit" << endl;
  cout << "Choice: ";
  
}

int main()
{
    
    int choice;
    bool is_running = true;
    string string_choice;
    vector<song> library;
    
    
    load(library);
    
    while(is_running)
    {
        main_menu();
        
        getline(cin, string_choice);
        choice = stoi(string_choice);
        
        switch(choice)
        {
            case 1: view_songs(library); pause(); break;
            case 2: add_song(library); pause(); break;
            case 3: play_song(library); pause(); break;
            case 4: shuffle(library); pause(); break;
            case 5: view_statistics(library); pause(); break;
            case 6: save(library); pause(); break;
            case 7: is_running = false; break;
            default: cout << "Enter a number between 1 and 7." << endl; pause();
            
        }
       
    }
}
