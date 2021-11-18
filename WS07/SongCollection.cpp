#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include "SongCollection.h"

namespace sdds{
    void SongCollection::trim(std::string& str)
    {
        str.erase(0, str.find_first_not_of(' '));
        str.erase(str.find_last_not_of(' ') + 1);

    }
    SongCollection::SongCollection(const char* fileName)
    {
        std::ifstream file(fileName);

        if (!file)
        {
            throw "ERROR, invalid filename!";
        }
        if (file)
        {
            while (file.good())
            {
                Song songs;
                std::string line;
                /*std::string year, length, price;*/

                std::getline(file, line, '\n');

                songs.m_title = line.substr(0, 25);
                songs.m_artist = line.substr(25, 25);
                songs.m_album = line.substr(50, 25);
                /*year = line.substr(75, 5);
                length = line.substr(80, 5);
                price = line.substr(85, 5);*/

                trim(songs.m_title);
                trim(songs.m_artist);
                trim(songs.m_album);

                    songs.m_length = std::stoi(line.substr(80, 5));
                    songs.m_price = std::stod(line.substr(85, 5));
                try
                {
                    songs.m_year = std::stoi(line.substr(75, 5));
                }
                catch (...)
                {
                    

                }

                m_collection.push_back(songs);
            }

        }
    }
    void SongCollection::display(std::ostream& out) const
    {
        

        std::for_each(m_collection.begin(), m_collection.end(), [&out](const Song& song) {

            out << song << std::endl;

        });

        auto sum = std::accumulate(m_collection.begin(), m_collection.end(), 0,
            [](const size_t& num,const Song& song){

                return num + song.m_length;    

            });

        out << "----------------------------------------------------------------------------------------" << std::endl;

        out << "|                                                        Total Listening Time: ";
        out << sum / 3600 << ":";
        out << (sum / 60) % 60 << ":";
        out << sum % 60;
        out << " |" << std::endl;
        
            

    }

    void SongCollection::sort(const std::string& value)
    {
        if (value == "title")
        {
            std::sort(m_collection.begin(), m_collection.end(), [](const Song& a, const Song& b) {
                return a.m_title < b.m_title;
                });
        }
        else if (value == "album")
        {
            std::sort(m_collection.begin(), m_collection.end(), [](const Song& a, const Song& b) {
                return a.m_album < b.m_album;
                });

        }
        else if (value == "length")
        {
            std::sort(m_collection.begin(), m_collection.end(), [](const Song& a, const Song& b) {
                return a.m_length < b.m_length;
                });
        }

    }

    void SongCollection::cleanAlbum()
    {
    
        std::for_each(m_collection.begin(), m_collection.end(), [](Song& song) {
            if (song.m_album == "[None]")
                song.m_album = "";
            });

    }

    bool SongCollection::inCollection(const std::string& artist) const
    {


        return std::any_of(m_collection.begin(), m_collection.end(), [=](const Song& song) {

            return song.m_artist == artist;
            });

    }

    std::list<Song> SongCollection::getSongsForArtist(const std::string& artist) const
    {

        auto cnt = std::count_if(m_collection.begin(), m_collection.end(), [artist](const Song& song) {

            return song.m_artist == artist;

            });
        
        std::list<Song> list(cnt);

        std::copy_if(m_collection.begin(), m_collection.end(), list.begin(), [artist](const Song& song) {

            return song.m_artist == artist;
            });

        return list;
    }

  
  
    std::ostream& operator<<(std::ostream& out, const Song& theSong)
    {
        out << "| " << std::setw(20) << std::left << theSong.m_title << " | ";
        out << std::setw(15) << std::left << theSong.m_artist << " | ";
        out << std::setw(20) << std::left << theSong.m_album << " | ";
        if (theSong.m_year)
        {
            out << std::setw(6) << std::right << theSong.m_year << " | ";
        }
        else {
            out << std::setw(6) << std::right << " " << " | ";

        }
        out << theSong.m_length / 60 << ":"; 
        out << std::setw(2) << std::setfill('0') << (theSong.m_length  % 60) << " | ";
        out << std::setfill(' ') << theSong.m_price << " |";

        return out;
    }

}