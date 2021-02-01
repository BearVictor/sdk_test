"""Compare json from scenario_run script and expected json """
from scenario_run import scenarios_run


def test_scenarios_run():
    paths_to_csv_scenarios = ["csv_scenarios/basic_use_case.csv",
                              "csv_scenarios/get_search_le.csv",
                              ]
    for path in paths_to_csv_scenarios:
        expected_path = scenarios_run(path)
        with open("delegate_output.json", "r") as output:
            present_output = output.read()

        with open(expected_path, "r") as output:
            expected_output = output.read()

        assert present_output == expected_output
