#ifndef UTILITY_H
#define UTILITY_H


class utility{

public:

    static const int framewidth=800;
    static const int frameheight=600;
    static const int charactersize=50;

   /* static bool intersect(int x1,int y1,int x2,int y2)
    {
        return f(x1,y1,x2,y2) or f(x1,y1,x2+charactersize,y2) or
               f(x1,y1,x2,y2+charactersize) or f(x1,y1,x2+charactersize,y2+charactersize);
    }
    bool f(int x1,int y1,int x2,int y2)
    {
        if((x2>= x1 and x2<=x1+charactersize and
                y2>=y1 and y2<=y1+charactersize))
            return true;
        return false;
    }

*/

};

#endif // UTILITY_H
