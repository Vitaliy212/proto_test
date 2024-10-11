#include <iostream>
#include <fstream>
#include <string>
#include "model.pb.h"


int main() {

    MyModel myModel;

    MyModel::Response* myModel_response = myModel.mutable_response();
    MyModel::Response::Body* myModel_response_body = myModel_response->mutable_body();
    MyModel::Response::Body::Head* myModel_response_body_head = myModel_response_body->mutable_head();
    MyModel::Response::Body::Head::Environment* myModel_response_body_head_environment = myModel_response_body_head->mutable_environment();
    MyModel::Response::Body::Torso* myModel_response_body_torso = myModel_response_body->mutable_torso();
    MyModel::Response::Body::Torso::Environment* myModel_response_body_torso_environment = myModel_response_body_torso->mutable_environment();
    MyModel::Response::Body::Clothing* myModel_response_body_Clothing = myModel_response_body->mutable_clothing();
    MyModel::Response::Body::Clothing::Fabric* myModel_response_body_Clothing_fabric = myModel_response_body_Clothing->mutable_fabric();

    myModel_response_body->set_id(2);
    myModel_response_body->set_hash("522Hash");
    myModel_response_body_head_environment->set_id(1);
    myModel_response_body_head_environment->set_hash("722Hash");
    myModel_response_body_head_environment->set_typeenv("Water");
    myModel_response_body_head_environment->set_temperatureincelsius(120);
    myModel_response_body_head_environment->set_humidityinpercent(55);
    myModel_response_body_head_environment->set_windvelocity(1);

    myModel_response_body_torso_environment->set_id(1);
    myModel_response_body_torso_environment->set_hash("722Hash");
    myModel_response_body_torso_environment->set_typeenv("Air");
    myModel_response_body_torso_environment->set_temperatureincelsius(120);
    myModel_response_body_torso_environment->set_humidityinpercent(55);
    myModel_response_body_torso_environment->set_windvelocity(2);

    myModel_response_body_Clothing->set_id(1);
    myModel_response_body_Clothing->set_hash("722Hash");
    myModel_response_body_Clothing->set_covering("Air");

    myModel_response_body_Clothing_fabric->set_id(1);
    myModel_response_body_Clothing_fabric->set_hash("722Hash");
    myModel_response_body_Clothing_fabric->set_ref("0");
    myModel_response_body_Clothing_fabric->set_rf("0");
    myModel_response_body_Clothing_fabric->set_ip("0");
    myModel_response_body_Clothing_fabric->set_density("0");
    myModel_response_body_Clothing_fabric->set_thickness("0");


    // Серіалізація у файл
    std::ofstream output("myModel.bin", std::ios::binary);

    if (!myModel.SerializeToOstream(&output)) {
        std::cerr << "Failed to serialize data" << std::endl;
        return -1;
    }
    output.close();

    std::cout << "Serialization is successful" << std::endl;


    std::ifstream input("myModel.bin", std::ios::binary);

    MyModel model;

    // Десеріалізація даних
    if (!model.ParseFromIstream(&input)) {
        std::cerr << "Failed to deserialize data" << std::endl;
        return -1;
    }
    input.close();

    std::cout << "Deserialization successful. ID: " << model.response().body().id() << std::endl;

    return 0;
}