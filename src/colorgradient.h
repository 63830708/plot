/***************************************************************************
**                                                                        **
**  QCustomPlot, an easy to use, modern plotting widget for Qt            **
**  Copyright (C) 2011, 2012, 2013, 2014 Emanuel Eichhammer               **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Emanuel Eichhammer                                   **
**  Website/Contact: http://www.qcustomplot.com/                          **
**             Date: 28.01.14                                             **
**          Version: 1.2.0-beta                                           **
****************************************************************************/

#ifndef QCP_COLORGRADIENT_H
#define QCP_COLORGRADIENT_H

#include "global.h"
#include "range.h"

class QCP_LIB_DECL QCPColorGradient
{
  Q_GADGET
public:
  /*!
    Defines the color spaces in which color interpolation between gradient stops can be performed.
    
    \see setColorInterpolation
  */
  enum ColorInterpolation {ciRGB,
                           ciHSV
                          };
  Q_ENUMS(ColorInterpolation)
  
  /*!
    Defines the available presets that can be loaded with \ref loadPreset. See the documentation
    there for an image of the presets.
  */
  enum GradientPreset {gpGrayscale,
                       gpHot,
                       gpCold,
                       gpNight,
                       gpCandy,
                       gpGeography,
                       gpIon,
                       gpThermal,
                       gpPolar,
                       gpSpectrum,
                       gpJet,
                       gpHues,
                      };
  Q_ENUMS(GradientPreset)
  
  QCPColorGradient(GradientPreset preset=gpCold);
  bool operator==(const QCPColorGradient &other) const;
  bool operator!=(const QCPColorGradient &other) const { return !(*this == other); }
  
  // getters:
  int levelCount() const { return mLevelCount; }
  QMap<double, QColor> colorStops() const { return mColorStops; }
  ColorInterpolation colorInterpolation() const { return mColorInterpolation; }
  bool periodic() const { return mPeriodic; }
  
  // setters:
  void setLevelCount(int n);
  void setColorStops(const QMap<double, QColor> &colorStops);
  void setColorStopAt(double position, const QColor &color);
  void setColorInterpolation(ColorInterpolation interpolation);
  void setPeriodic(bool enabled);
  
  // non-property methods:
  void colorize(const double *data, const QCPRange &range, QRgb *scanLine, int n, int dataIndexFactor=1, bool logarithmic=false);
  QRgb color(double position, const QCPRange &range, bool logarithmic=false);
  void loadPreset(GradientPreset preset);
  void clearColorStops();
  QCPColorGradient inverted() const;
  
protected:
  void updateColorBuffer();
  
  // property members:
  int mLevelCount;
  QMap<double, QColor> mColorStops;
  ColorInterpolation mColorInterpolation;
  bool mPeriodic;
  
  // non-property members:
  QVector<QRgb> mColorBuffer;
  bool mColorBufferInvalidated;
};

#endif // QCP_COLORGRADIENT_H