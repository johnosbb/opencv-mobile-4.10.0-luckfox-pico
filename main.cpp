#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <unistd.h> // sleep()

int main()
{
    fprintf(stderr, "Still Image Capture Example..\n");
    cv::VideoCapture cap;
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 320);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 240);
    cap.open(0);
    if (!cap.isOpened())
    {
        fprintf(stderr, "ERROR: Cannot open camera.\n");
        return -1;
    }
    else
        fprintf(stderr, "Opened camera..\n");

    const int w = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    const int h = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    fprintf(stderr, "Image Dimensions: %d x %d\n", w, h);

    cv::Mat bgr[9];
    for (int i = 0; i < 9; i++)
    {
        cap >> bgr[i];
        if (bgr[i].empty())
        {
            fprintf(stderr, "ERROR: Frame %d is empty\n", i);
            return -1;
        }
        fprintf(stderr, "Captured frame %d: type = %d, channels = %d\n",
                i, bgr[i].type(), bgr[i].channels());

        // Save intermediate frames for debugging
        std::string filename = "frame_" + std::to_string(i) + ".jpg";
        cv::imwrite(filename, bgr[i]);
        sleep(1);
    }

    cap.release();

    // combine into big image
    {
        cv::Mat out(h * 3, w * 3, CV_8UC3);
        bgr[0].copyTo(out(cv::Rect(0, 0, w, h)));
        bgr[1].copyTo(out(cv::Rect(w, 0, w, h)));
        bgr[2].copyTo(out(cv::Rect(w * 2, 0, w, h)));
        bgr[3].copyTo(out(cv::Rect(0, h, w, h)));
        bgr[4].copyTo(out(cv::Rect(w, h, w, h)));
        bgr[5].copyTo(out(cv::Rect(w * 2, h, w, h)));
        bgr[6].copyTo(out(cv::Rect(0, h * 2, w, h)));
        bgr[7].copyTo(out(cv::Rect(w, h * 2, w, h)));
        bgr[8].copyTo(out(cv::Rect(w * 2, h * 2, w, h)));

        if (!cv::imwrite("out.jpg", out))
        {
            fprintf(stderr, "ERROR: Failed to write out.jpg\n");
            return -1;
        }
    }

    return 0;
}
