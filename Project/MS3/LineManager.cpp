#include <fstream>
#include <string>
#include <algorithm>
#include <exception>

#include "LineManager.h"
#include "Utilities.h"


namespace sdds {


    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) :m_firstStation{ nullptr }, m_cntCustomerOrder{}
    {
        
            std::ifstream fin(file);

            std::string line;
            Utilities util;


            if (!fin)
            {
                throw "ERROR, cannot open file";
            }


            while (std::getline(fin, line)) {

                size_t next_pos = 0;
                bool more{};
                std::string curr, next;

                try {
                    curr = util.extractToken(line, next_pos, more);

                    if (more)
                        next = util.extractToken(line, next_pos, more);
                }
                catch (std::exception& e)
                {
                    std::cout << e.what();
                }
                std::for_each(stations.begin(), stations.end(), [&](Workstation* w) {
                    if (w->getItemName() == curr)
                    {
                        std::for_each(stations.begin(), stations.end(), [&](Workstation* j) {

                            if (j->getItemName() == next)
                                w->setNextStation(j);
                            });
                        activeLine.push_back(w);
                    }
                    });
            }
            m_firstStation = activeLine.front();
            m_cntCustomerOrder = pending.size();
        
        
    }



    void LineManager::linkStations()
    {
        std::vector<Workstation* > ordered;
        Workstation* p = m_firstStation;

        do {

            ordered.push_back(p);
            p = p->getNextStation();

        } while (p);

        activeLine = ordered;
    }

    bool sdds::LineManager::run(std::ostream& os)
    {
        static size_t cnt = 0;

        os << "Line Manager Iteration: " << ++cnt << std::endl;

        if (!pending.empty()) {
            *m_firstStation += std::move(pending.front());
            pending.pop_front();
        }

        std::for_each(activeLine.begin(), activeLine.end(), [&os](Workstation* w) {
            w->fill(os);
            });

        std::for_each(activeLine.begin(), activeLine.end(), [](Workstation* w) {
            w->attemptToMoveOrder();
            });
        

        return (m_cntCustomerOrder == (completed.size() + incomplete.size()));
        

    }

    void sdds::LineManager::display(std::ostream& os) const
    {
        std::for_each(activeLine.begin(), activeLine.end(), [&os](const Workstation* w) {
            w->display(os);
            });

    }





}
       


