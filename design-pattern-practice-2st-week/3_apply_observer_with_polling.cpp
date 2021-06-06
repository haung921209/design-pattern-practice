#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>

using namespace std;

class Observee{
public:
    void update();
};

class WeatherData :public Observee{
private:
    vector<float> temperature;
    vector<float> humidity;
    vector<float> preesure;
    bool flag;

public:
    WeatherData(){
        this->flag=false;
    };
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
        this->flag=true;
        
    }
    
    bool isUpdated(){
        return this->flag;
    }
    
    void notifyUpdateCompleted(){
        this->flag = false;
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
        display();
    }
    
    void display(){
        if(weatherData->isUpdated()){
            vector<float> savedHumidity = weatherData->getHumidity();
            vector<float> savedTemperature = weatherData->getTemparature();
            vector<float> savedPreesure = weatherData->getPreesure();
            //display data and update

            weatherData->notifyUpdateCompleted();
        }
    }
    
};

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    WeatherData* weatherData = new WeatherData();
    vector<float> temperatureData = {10,15,12};
    vector<float> preesureData = {12, 21, 13};
    vector<float> humidityData = {21, 42, 19};
    WeatherDataDisplay weatherDataDisplay;
    weatherData->setMonitoringData(temperatureData, preesureData, humidityData);
    weatherDataDisplay.update(weatherData);
    
    
    return 0;
}
