"""Automatically wrapper. Open .csv file, get scenario from them,and run following function"""
import csv
import sys
import time

sys.path.append("../sdk_python/")
import python_functions


def read_csv_file(path: str, parameters_pack: int) -> dict:
    """
    Open csv file, which locate in currently directory.
    All rows are saved like dict object.
    All rows saved in common list
    :param path:  path to .csv file
    :param parameters_pack: number with parameters from the CSV file using
    :return: dict with parameters
    """
    all_parameters_for_scenario = []
    with open(path, newline='') as csv_file:
        reader = csv.DictReader(csv_file, delimiter=python_functions.DELIMITER)
        for row in reader:
            all_parameters_for_scenario.append(row)

    return all_parameters_for_scenario[parameters_pack]


def scenarios_run(path: str, parameters_pack: int = 0) -> str:
    """
    Open csv file. Then run all function from if,using read parameters
    :param path:  path to .csv file
    :param parameters_pack: number with parameters from the CSV file using
    :return:
    """
    all_parameters_for_scenario = read_csv_file(path, parameters_pack)  # save csv file
    name_of_functions = all_parameters_for_scenario.keys()  # save all name of function

    #one by one call function
    for name in name_of_functions:
        try:
            method_to_call = getattr(python_functions, name)
            if name == "output_json":
                expected_path = method_to_call(all_parameters_for_scenario[name])
            method_to_call(all_parameters_for_scenario[name])
            time.sleep(python_functions.DELAY)
        except AttributeError:
            print("module 'python_functions' has no attribute " + name)
            continue
    return expected_path


if __name__ == '__main__':
    scenarios_run("csv_scenarios/basic_use_case.csv")
