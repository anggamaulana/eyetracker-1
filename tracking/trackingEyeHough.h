/**
 * @file trckingHough.h
 * @brief Captures the frames of the eye
 *
 * Image Processing and Pattern Recognition
 * (Bildverarbeitung und Mustererkennung)
 * Project
 */

#ifndef __TRACKINGEYEHOUGH_H__
#define __TRACKINGEYEHOUGH_H__

// stl
#include <vector>

// opencv
#include <cv.h>

typedef struct CallbackData {
  TrackedPupil *detected_positions;  
  TrackedPupil *pupil_to_track; 
} CallbackData;

void mouse_callback(int event, int x, int y, int flags, void* user_data);

class TrackingEyeHough
{

  EyeCapture* m_eye;
  TrackedPupil m_curr_pupil;
  const int m_eye_cam;

  int m_bw_threshold;

  // HoughCircles Parameters
  double m_hough_minDist;
  double m_hough_dp;
  double m_hough_param1;
  double m_hough_param2;
  double m_hough_minRadius;
  double m_hough_maxRadius;

public:

  /**
   * Constructor
   * @param 
   */
  TrackingEyeHough(const int eye_cam);

  /**
   * Destructor
   */
  virtual ~TrackingEyeHough();

  /**
   * Return tracked pupils
   */
  TrackedPupil getPupil();
  
  /**
   * Print parameters
   */
  void printParams();

  
private:

  /**
   * disabled default constructor
   */
  TrackingEyeHough();

  /**
   * disabled copy constructor
   */
  TrackingEyeHough(const TrackingEyeHough&);
  
  /**
   * disabled copy constructor
   */
  TrackingEyeHough& operator = (const TrackingEyeHough&);

  void HoughCirclesPupil(TrackedPupil &pupil);

  double distance(const cv::Point2f pupil_to_track, const cv::Point2f found_pupil);
  
  
};

#endif //__TRACKINGEYEHOUGH_H__
