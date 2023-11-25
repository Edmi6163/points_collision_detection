def count_phrase(file_path):
    
    try:
        with open(file_path, "r") as file:
            content = file.read()
            occurrences = content.lower().split("\n")
            phrase_count = {}

            for phrase in occurrences:
                phrase_count[phrase] = phrase_count.get(phrase, 0) + 1

            return phrase_count
    except FileNotFoundError:
        print(f"Error: {file_path} not found")
        return {}

if __name__ == "__main__":
    file_path = "log.log"
    occurrences = count_phrase(file_path)
    for phrase, count in occurrences.items():
        if count > 10: #TODO here the count value is just to filter the output  
            print(f"the phrase {phrase} appears {count} times in the file")