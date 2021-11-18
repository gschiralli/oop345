#ifndef SDDS_SONG_COLLECTION_H
#define SDDS_SONG_COLLECTION_H
#include <string>
#include <vector>
#include <iostream>
#include <list>
namespace sdds {

	struct Song {
		std::string m_artist{};
		std::string m_title{};
		std::string m_album{};
		double m_price{};
		size_t m_year{};
		size_t m_length{};
	};

	class SongCollection
	{
		std::vector<Song> m_collection;

		void trim(std::string& str);
	public:
		SongCollection(const char* fileName);
		void display(std::ostream& out) const;
		void sort(const std::string& value);
		void cleanAlbum();
		bool inCollection(const std::string& artist) const;
		std::list<Song> getSongsForArtist(const std::string& artist) const;


	};
		std::ostream& operator<<(std::ostream& out, const Song& theSong);
}


#endif // !SDDS_SONG_COLLECTION_H

