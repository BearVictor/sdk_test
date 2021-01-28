"""Compare json from basi_use_case.py script and expected json """
from get_search_le import scenario

def test_basic_use_case_pack_1():
    """take parameters from the first-row csv file"""
    path = scenario()
    present_output =[]
    with open("delegate_output.json", "r") as output:
        present_output.append(output.readlines())

    expected_output = []
    with open(path, "r") as output:
        expected_output.append(output.readlines())

    assert present_output == expected_output
