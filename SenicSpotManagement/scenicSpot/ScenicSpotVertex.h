//
// Created by 陈格平 on 2023/1/28.
//

#ifndef SENICSPOTMANAGEMENT_SCENICSPOTVERTEX_H
#define SENICSPOTMANAGEMENT_SCENICSPOTVERTEX_H
#include "../utils/graph/Vertex.h"

class ScenicSpotVertex : public Vertex{
private:
    string spotName;//name of spot
    string intro;//intro of spot
    int welcome;//how popular
    bool relaxPlace;//have relax place
    bool restRoom;//have restRoom

    int popularRanking;
public:
    explicit ScenicSpotVertex(string spotName = "NONAME",
                     string intro = " ", int welcome = -1,
                     bool relaxPlace = 1, bool restRoom = 1,
                     int popularRanking = -1);
    void setSpotName(string name);
    void setIntro(string introInfo);
    void setWelcome(int welcomeWeight);
    void setRelaxPlace(bool hasRelaxPlace);
    void setRestRoom(bool hasRestRoom);
    void setPopularRanking(int ranking);

    string getSpotName();
    string getIntro();
    int getWelcome() const;
    bool hasRelaxPlace() const;
    bool hasRestRoom() const;
    int getPopularRanking() const;

    void toString();
};


#endif //SENICSPOTMANAGEMENT_SCENICSPOTVERTEX_H
