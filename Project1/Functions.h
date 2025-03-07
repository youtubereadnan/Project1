#pragma once
#include<iostream>
#include<conio.h>
#include <windows.h>
using namespace std;

struct Movie
{
    char Movie_Name[50], Director[50], Genre[50];
    float Popularity_Rating, Price;
};
void firstfill(Movie arr[], Movie movie1, Movie movie2, Movie movie3, Movie movie4, Movie movie5)
{
    arr[0] = movie1;
    arr[1] = movie2;
    arr[2] = movie3;
    arr[3] = movie4;
    arr[4] = movie5;
}
void Show_movie(Movie arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Movie - " << arr[i].Movie_Name << "\nDirector - " << arr[i].Director << "\nGenre - " << arr[i].Genre << "\nRating - " << arr[i].Popularity_Rating << "\nPrice - " << arr[i].Price << "\n\n";
    }
}

void Sort_by_name(Movie arr[], int size)
{
    for (char i = 65; i < 91; i++)
    {
        for (char j = 0; j < size; j++)
        {
            if (arr[j].Movie_Name[0] == i || arr[j].Movie_Name[0] == i + 32)
            {
                cout << arr[j].Movie_Name << "\n" << arr[j].Director << "\n" << arr[j].Genre << "\n" << arr[j].Popularity_Rating << "\n" << arr[j].Price << "\n\n";
            }
        }
    }
    for (char j = 0; j < size; j++)
    {
        if (!(arr[j].Movie_Name[0] >= 65 && arr[j].Movie_Name[0] <= 90 || arr[j].Movie_Name[0] >= 65 + 32 && arr[j].Movie_Name[0] <= 90 + 32))
        {
            cout << arr[j].Movie_Name << "\n" << arr[j].Director << "\n" << arr[j].Genre << "\n" << arr[j].Popularity_Rating << "\n" << arr[j].Price << "\n\n";
        }
    }
}
void Sort_by_Director(Movie arr[], int size)
{
    for (char i = 65; i < 91; i++)
    {
        for (char j = 0; j < size; j++)
        {
            if (arr[j].Director[0] == i || arr[j].Director[0] == i + 32)
            {
                cout << arr[j].Movie_Name << "\n" << arr[j].Director << "\n" << arr[j].Genre << "\n" << arr[j].Popularity_Rating << "\n" << arr[j].Price << "\n\n";
            }
        }
    }
}
void Sort_by_genre(Movie arr[], int size)
{
    for (char i = 65; i < 91; i++)
    {
        for (char j = 0; j < size; j++)
        {
            if (arr[j].Genre[0] == i || arr[j].Genre[0] == i + 32)
            {
                cout << arr[j].Movie_Name << "\n" << arr[j].Director << "\n" << arr[j].Genre << "\n" << arr[j].Popularity_Rating << "\n" << arr[j].Price << "\n\n";
            }
        }
    }
}
void Movie_QuickSort_Popularity_Rating(Movie arr[], int length) {
    int i{ 0 }, j = length;
    int pos{};
    Movie tmp;
    pos = arr[length / 2].Popularity_Rating;



    do
    {
        while (arr[i].Popularity_Rating > pos) i++;
        while (arr[j].Popularity_Rating < pos) j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }

    } while (i <= j);

    if (j > 0) Movie_QuickSort_Popularity_Rating(arr, j);
    if (length > i) Movie_QuickSort_Popularity_Rating(arr + i, length - i);
}
void Sort_by_popular(Movie arr[], int size)
{
    Movie* tmp = new Movie[size];
    for (int i = 0; i < size; i++)
    {
        tmp[i] = arr[i];
    }
    Movie_QuickSort_Popularity_Rating(tmp, size);
    Show_movie(tmp, size);
    delete[] tmp;
}
void Add_New_Movie(Movie*& arr, int& length)
{
    Movie* tmp = new Movie[length + 1];
    for (int i = 0; i < length; i++) {
        tmp[i] = arr[i];
    }
    delete[] arr;
    arr = tmp;

    cout << "\nEnter movie name:";
    gets_s(arr[length].Movie_Name, 50);
    cout << "\nEnter Director name:";
    gets_s(arr[length].Director, 50);
    cout << "\nEnter genre:";
    gets_s(arr[length].Genre, 50);
    cout << "Enter popularity rating:";
    cin >> arr[length].Popularity_Rating;
    cout << "Enter price:";
    cin >> arr[length].Price;

    length++;
}
void Search_by_name(Movie movie[], char search_name[], int size)
{
    bool tmp{};
    for (int i = 0; i < size; i++)
    {
        if (strcmp(search_name, movie[i].Movie_Name) == 0)
        {
            cout << movie[i].Movie_Name << "\n" << movie[i].Director << "\n" << movie[i].Genre << "\n" << movie[i].Popularity_Rating << "\n" << movie[i].Price;
            tmp = true;
        }
    }
    if (!tmp)
    {
        cout << "There is no such movie";
    }
}
void Search_by_director(Movie movie[], char search_director[], int size)
{
    bool tmp{};
    for (int i = 0; i < size; i++)
    {
        if (strcmp(search_director, movie[i].Director) == 0)
        {
            cout << movie[i].Movie_Name << "\n" << movie[i].Director << "\n" << movie[i].Genre << "\n" << movie[i].Popularity_Rating << "\n" << movie[i].Price;
            tmp = true;
        }
    }
    if (!tmp)
    {
        cout << "There is no such director";
    }
}
void Search_by_genre(Movie movie[], char search_genre[], int size)
{
    bool tmp{};
    for (int i = 0; i < size; i++)
    {
        if (strcmp(search_genre, movie[i].Genre) == 0)
        {
            cout << movie[i].Movie_Name << "\n" << movie[i].Director << "\n" << movie[i].Genre << "\n" << movie[i].Popularity_Rating << "\n" << movie[i].Price;
            tmp = true;
        }
    }
    if (!tmp)
    {
        cout << "There is no such genre";
    }
}
void Most_popular_movie_by_genre(Movie arr[], char popular_genre[], int size)
{
    int tmp_size{};
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].Genre, popular_genre) == 0)
        {
            tmp_size++;
        }
    }

    if (tmp_size == 0)
    {
        cout << "There is no such genre" << endl;
        return;
    }
    Movie* tmp = new Movie[size];
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].Genre, popular_genre) == 0)
        {
            tmp[index++] = arr[i];
        }
    }
    Movie_QuickSort_Popularity_Rating(tmp, tmp_size);
    Show_movie(tmp, tmp_size);
    delete[] tmp;
}