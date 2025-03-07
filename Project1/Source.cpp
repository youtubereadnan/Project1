#include "Functions.h"

int main()
{
    Movie Sonik
    {
      "Sonik 3",
      "Ceff Fauler",
      "Fantasy",
      94,
      30
    };
    Movie Iron_Man
    {
      "Iron Man",
      "Jon Favreau",
      "Action",
      91,
      25
    };
    Movie SpiderMan
    {
      "Spider-Man: Into the Spider-Verse",
      "Bob Persichetti",
      "Animation",
      84,
      25
    };
    Movie Saw
    {
      "Saw X",
      "Kevin Greutert",
      "Horror",
      71,
      30
    };
    Movie six
    {
      "666",
      "Satana !God",
      "Horror",
      666,
      666
    };
    int size{ 5 };
    Movie* movie = new Movie[size];
    firstfill(movie, Sonik, Iron_Man, SpiderMan, Saw, six);
    while (true)
    {
        cout << "1)Show movie\n\n2)Sort\n\n3)Search\n\n4)Add new disk\n\n5)Exit\n\nWhat do you want?";
        char choice = _getch();
        if (choice == '1')
        {
            system("cls");
            Show_movie(movie, size);
        }
        else if (choice == '2')
        {
            system("cls");
            cout << "1)Sort_by_movie_name\n\n2)Sort_by_director\n\n3)Sort_by_genre\n\n4)Sort_by_popular\n\n5)Exit\n\nWhat do you want?\n\n";
            char choice_sort = _getch();
            if (choice_sort == '1')
            {
                Sort_by_name(movie, size);
                cout << "\n\n";
            }
            else if (choice_sort == '2')
            {
                Sort_by_Director(movie, size);
                cout << "\n\n";
            }
            else if (choice_sort == '3')
            {
                Sort_by_genre(movie, size);
                cout << "\n\n";
            }
            else if (choice_sort == '4')
            {
                Sort_by_popular(movie, size);
                cout << "\n\n";
            }

            else if (choice_sort == '5')
            {
            }
            else
            {
                system("cls");
                cout << "I don't understand you\n\n";
            }
            cout << "Click enter to continue";
            _getch();
            system("cls");
        }
        else if (choice == '3')
        {
            system("cls");
            cout << "1)Search by movie name\n\n2)Search by director\n\n3)Search by genre\n\n4)Most popular movie by genre\n\n5)Exit";
            char choice_search = _getch();
            if (choice_search == '1')
            {
                cout << "\n\nEnter movie name:\n\n";
                char search_name[50];
                gets_s(search_name, 50);
                Search_by_name(movie, search_name, size);
            }
            else if (choice_search == '2')
            {
                cout << "\n\nEnter movie director:\n\n";
                char search_director[50];
                gets_s(search_director, 50);
                Search_by_director(movie, search_director, size);
            }
            else if (choice_search == '3')
            {
                cout << "\n\nEnter movie genre:\n\n";
                char search_genre[50];
                gets_s(search_genre, 50);
                Search_by_genre(movie, search_genre, size);
            }
            else if (choice_search == '4')
            {
                cout << "\n\nEnter movie genre:\n\n";
                char popular_genre[50];
                gets_s(popular_genre, 50);
                Most_popular_movie_by_genre(movie, popular_genre, size);
            }
            else if (choice_search == '5')
            {
            }
            else
            {
                system("cls");
                cout << "I don't understand you\n\n";
            }
            cout << "\n\nClick enter to continue";
            _getch();
            system("cls");
        }
        else if (choice == '4')
        {
            system("cls");
            Add_New_Movie(movie, size);
        }
        else if (choice == '5')
        {
            system("cls");
            cout << "\nBye";
            break;
        }
        else
        {
            system("cls");
            cout << "I don't understand you\n\n";
        }
    }
    delete[] movie;
    return 0;
}
