#ifndef PROGRESSVIEW_H
#define PROGRESSVIEW_H

#include "View.h"

class ProgressView : public View {
public:
    void draw();  // 2초 진행 바 출력
};

#endif // !PROGRESSVIEW_H