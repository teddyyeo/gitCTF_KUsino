#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <b64/cdecode.h>

int main() {
    const char *encoded_data = "SGVsbG8gV29ybGQh"; // 디코딩할 Base64 문자열

    struct base64_decode_ctx ctx;

    int dec_len = strlen(encoded_data);
    int buf_len = BASE64_DECODE_OUT_SIZE(dec_len);
    char *decoded_data = (char *)malloc(buf_len);

    base64_decode_init(&ctx);

    int written = base64_decode_update(&ctx, encoded_data, dec_len, decoded_data);
    written += base64_decode_final(&ctx, decoded_data + written);

    if (written < 0) {
        printf("디코딩 실패\n");
    } else {
        printf("디코딩된 데이터: %s\n", decoded_data);
    }

    free(decoded_data);

    return 0;
}