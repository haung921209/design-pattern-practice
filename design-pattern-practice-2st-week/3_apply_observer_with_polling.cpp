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
    bool flag

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
        
    }
    (vector<float>, vector<float>, vector<float>) update(){
        if(this->flag==true){
            //update and display data
            return (temperature, humidity, preesure);
        }
        // nothing updated
        
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
        if(WeatherData->update()){
            //display data and update
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
    weatherData->registerObserver(weatherDataDisplay);
    weatherData->setMonitoringData(temperatureData, preesureData, humidityData);
    
    return 0;
}
