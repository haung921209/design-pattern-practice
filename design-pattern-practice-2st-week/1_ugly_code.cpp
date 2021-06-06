#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


class WeatherData {
private:
    vector<float> temperature;
    vector<float> humidity;
    vector<float> preesure;
public:
    WeatherData(){};
    vector<float> getTemparature(){
        return this->temperature;
    }
    vector<float> getHumidity(){
        return this->humidity;
    }
    vector<float> getPreesure(){
        return this->preesure;
    }
    void setMonitoringData(vector<float> temperature, vector<float> humidity, vector<float> preesure){
        this->humidity = humidity;
        this->preesure = preesure;
        this->temperature = temperature;
    }
};

class WeatherDataDisplay{
private:
    WeatherData* weatherData;
public:
    WeatherDataDisplay(){};
    WeatherDataDisplay(WeatherData* weatherData){
        this->weatherData = weatherData;
    }
    
    void update(WeatherData* weatherData){
        this->weatherData = weatherData;
    }
    
    void display(){
        //display data
    }
    
};



int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    WeatherData* weatherData = new WeatherData();
    vector<float> temperatureData = {10,15,12};
    vector<float> preesureData = {12, 21, 13};
    vector<float> humidityData = {21, 42, 19};
    
    weatherData->setMonitoringData(temperatureData, preesureData, humidityData);
    WeatherDataDisplay weatherDataDisplay(weatherData);
    weatherDataDisplay.display();
    
    
    return 0;
}
