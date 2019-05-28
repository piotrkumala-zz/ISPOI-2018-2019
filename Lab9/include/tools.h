#pragma once

// Klasa implementujaca metody statyczne do porownywania i szukania roznych typow:
class tools{
public:

    template <typename T>

    // Funkcja zwracajaca mniejszy z dwoch argumentow dowolnych typow:
    static T smaller(const T& first, const T& second){
        if(first<second)
            return first;
        else
            return second;
    }

    template <typename T>

    // Funkcja zwracajaca wiekszy z dwoch argumentow dowolnych typow:
    static T larger(const T&first, const T& second){
        if(first>second)
            return first;
        else
            return second;
    }

    template <typename T>

    // Funkcja zwraca indeks szukanego elementu target w tablicy tab
    static int find(const T* tab, int size, const T& target){
        for (int i = 0; i < size; ++i){
            if(tab[i]==target)
                return i;
        }
        return size;
    }

};