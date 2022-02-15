#include <iostream>
#include <string>
using namespace std;

class MediaPlayer {
    public:
    virtual void play(string audioType, string fileName) = 0;
};

class LatestMediaPlayer {
    public:
        virtual void play(string fileName) = 0;
};

class VLC : public LatestMediaPlayer {
    public:
        void play(string fileName) {
            cout << "Playing VLC file" << endl;
        }
};

class MP4 : public LatestMediaPlayer {
    public:
        void play(string fileName) {
            cout << "Playing MP4 file" << endl;
        }
};

class Adapter : public MediaPlayer {
    public:
        LatestMediaPlayer* latestMediaPlayer;

        Adapter(string mediaType) {
            if(mediaType == "vlc") {
                latestMediaPlayer = new VLC;
            }
            else if (mediaType == "mp4") {
                latestMediaPlayer = new MP4;
            }
        }

        void play(string audioType, string fileName) {
            latestMediaPlayer->play(fileName);
        }
};

class AudioPlayer : public MediaPlayer {
    public:
        MediaPlayer* adapter;
        void play(string audioType, string fileName) {
            adapter = new Adapter(audioType);
            adapter->play(audioType, fileName);
        }
};

int main() {
    AudioPlayer* audioPlayer = new AudioPlayer;
    audioPlayer->play("mp4", "NovemberRain.mp4");
    audioPlayer->play("vlc", "HotelCalifornia.mp4");
}