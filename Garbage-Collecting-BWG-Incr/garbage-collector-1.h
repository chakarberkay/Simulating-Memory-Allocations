#include "memory.h"

class CollectorV1 {
    public:
        CollectorV1(Memory& memory);

        void countBlackNodes();
        void markNodesBlack();
        void newMarkingPhase();
        void collectingPahse();
        void collectGarbageNodes();
        void markSuspectedGray();
        void makeGrayWhite();
    private:
        int oldBlackCount, blackCount;
        Memory& memory;
        
};