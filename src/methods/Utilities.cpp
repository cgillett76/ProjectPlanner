#include "../headers/Utilities.h"

// returns year_month_day chrono date
std::chrono::year_month_day convertDate(std::string dateStr)
{
    unsigned int day, month;
    int year;

    std::sscanf(dateStr.c_str(), "%d-%d-%d", &day, &month, &year);

    std::chrono::day chronoDay{day};
    std::chrono::month chronoMonth{month};
    std::chrono::year chronoYear{year};

    std::chrono::year_month_day chronoDate(chronoYear, chronoMonth, chronoDay);

    return chronoDate;
}

// converts Chronon year_month_day to a string
std::string convertDateToString(std::chrono::year_month_day chronoDate)
{
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << static_cast<unsigned>(chronoDate.day()) << '-'
        << std::setw(2) << std::setfill('0') << static_cast<unsigned>(chronoDate.month()) << '-'
        << static_cast<int>(chronoDate.year());

    std::string dateStr = oss.str();
    return dateStr;
}

// prints a chrono date
void printChronoDate(std::chrono::year_month_day chronoDate)
{
    std::cout << chronoDate << std::endl;
}

// Openssl generate a hash
std::string generateHash(const std::string &input)
{
    EVP_MD_CTX *ctx = EVP_MD_CTX_new(); // Create digest context
    if (!ctx)
        throw std::runtime_error("Failed to create EVP_MD_CTX");

    if (EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr) != 1)
        throw std::runtime_error("EVP_DigestInit_ex failed");

    if (EVP_DigestUpdate(ctx, input.c_str(), input.size()) != 1)
        throw std::runtime_error("EVP_DigestUpdate failed");

    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int length = 0;

    if (EVP_DigestFinal_ex(ctx, hash, &length) != 1)
        throw std::runtime_error("EVP_DigestFinal_ex failed");

    EVP_MD_CTX_free(ctx); // Clean up

    // Convert to hex string
    std::ostringstream oss;
    for (unsigned int i = 0; i < length; ++i)
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];

    return oss.str();
}

bool generateEncryptedRsaPrivateKey(const std::string &filename, const std::string &passphrase)
{
    int bits = 2048;
    bool success{false};
    EVP_PKEY_CTX *ctx{nullptr};
    EVP_PKEY *privateKey{nullptr};
    FILE *filePtr{nullptr};

    OpenSSL_add_all_algorithms();

    ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, nullptr);
    const EVP_CIPHER *cipher = EVP_aes_256_cbc();
    if (!ctx)
    {
        goto cleanup;
    }

    if (EVP_PKEY_keygen_init(ctx) <= 0)
    {
        goto cleanup;
    }

    if (EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, bits) <= 0)
    {
        goto cleanup;
    }

    filePtr = fopen(filename.c_str(), "wb");
    if (!filePtr)
    {
        goto cleanup;
    }

    if (!PEM_write_PrivateKey(filePtr, privateKey, cipher, (unsigned char *)passphrase.c_str(), passphrase.length(), nullptr, nullptr))
    {
        goto cleanup;
    }

    success = true;

cleanup:
    if (filePtr)
        fclose(filePtr);
    if (privateKey)
        EVP_PKEY_free(privateKey);
    if (ctx)
        EVP_PKEY_CTX_free(ctx);

    return success;
}