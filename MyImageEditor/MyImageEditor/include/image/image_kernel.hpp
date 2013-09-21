
#include <QtCore\QtCore>

template<class valueType, int Rows, int Columns>
class TImageKernel
{

public:

    enum
    {
        ROW_COUNT = Rows,
        COL_COUNT = Columns,
        SIZE = Rows * Columns
    };

    typedef valueType valueType;

    valueType& operator()(const int& f_xIndex, const int& f_yIndex)
    {
        Q_ASSERT(f_yIndex < ROW_COUNT);
        Q_ASSERT(f_xIndex < COL_COUNT);

        return m_kernel[f_xIndex][f_yIndex];
    }

    valueType operator()(const int& f_xIndex, const int& f_yIndex) const
    {
        Q_ASSERT(f_yIndex < ROW_COUNT);
        Q_ASSERT(f_xIndex < COL_COUNT);

        return m_kernel[f_xIndex][f_yIndex];
    }

    valueType sum()
    {
        valueType l_sum = static_cast<valueType>(0);
        for(int l_x = 0; l_x < ROW_COUNT; l_x++)
        {
            for(int l_y = 0; l_y < COL_COUNT; l_y++)
            {
                l_sum += m_kernel[l_y][l_x];
            }
        }

        return l_sum;
    }

    valueType m_kernel[COL_COUNT][ROW_COUNT];
};