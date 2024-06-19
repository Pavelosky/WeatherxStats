import csv

def retain_first_three_columns(input_file, output_file):
    with open(input_file, mode='r', newline='', encoding='utf-8') as infile:
        reader = csv.reader(infile)
        rows = [row[:3] for row in reader]
        
    with open(output_file, mode='w', newline='', encoding='utf-8') as outfile:
        writer = csv.writer(outfile)
        writer.writerows(rows)

# Usage
input_file = 'weather_data_EU_1980-2019_temp_only.csv'  # Replace with the path to your input CSV file
output_file = 'output.csv'  # Replace with the desired path for the output CSV file
retain_first_three_columns(input_file, output_file)
