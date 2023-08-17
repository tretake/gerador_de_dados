#include <iostream>
#include "include/curl/curl.h"

CURL *curl;
CURLcode res;
struct curl_slist *headers = NULL; // init to NULL is important
headers = curl_slist_append(headers, "Accept: application/json");

curl = curl_easy_init();

if (curl)
{

    curl_easy_setopt(curl, CURLOPT_URL, "http://web.com/api/json/123");
    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    // curl_easy_setopt(curl, CURLOPT_URL, "http://web.com/123.html");//this works!!!
    res = curl_easy_perform(curl);

    if (CURLE_OK == res)
    {
        char *ct;
        /* ask for the content-type */
        res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
        if ((CURLE_OK == res) && ct)
            printf("We received Content-Type: %s\n", ct);
    }
}
/* always cleanup */
curl_easy_cleanup(curl);