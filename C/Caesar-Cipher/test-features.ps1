# Caesar Cipher Feature Test Script
Write-Host "`n==================================================" -ForegroundColor Cyan
Write-Host "   TESTING ENHANCED CAESAR CIPHER FEATURES" -ForegroundColor Cyan
Write-Host "==================================================" -ForegroundColor Cyan

# Test 1: Encrypt a file with auto extension
Write-Host "`n[TEST 1] Encrypting test.txt with shift=5..." -ForegroundColor Yellow
@"
1
test.txt

5
"@ | .\caesar-cipher.exe 2>$null | Select-String -Pattern "encrypted|Time|File size|Total chars" | ForEach-Object { $_.Line }

Start-Sleep -Seconds 1

# Check if encrypted file was created
if (Test-Path "test.txt.enc") {
    Write-Host "`n✅ Encrypted file created: test.txt.enc" -ForegroundColor Green
    Write-Host "Original content:"
    Get-Content test.txt | Select-Object -First 2
    Write-Host "`nEncrypted content:"
    Get-Content test.txt.enc | Select-Object -First 2
} else {
    Write-Host "❌ Encrypted file not created" -ForegroundColor Red
}

# Test 2: Brute Force Decryption
Write-Host "`n`n[TEST 2] Running Brute Force Decryption..." -ForegroundColor Yellow
Write-Host "Trying all 25 possible shifts on test.txt.enc:" -ForegroundColor Cyan
@"
3
test.txt.enc
"@ | .\caesar-cipher.exe 2>$null | Select-String -Pattern "Shift" | Select-Object -First 10

# Test 3: Frequency Analysis
Write-Host "`n`n[TEST 3] Running Frequency Analysis on sample.txt..." -ForegroundColor Yellow
@"
4
sample.txt
"@ | .\caesar-cipher.exe 2>$null | Select-String -Pattern "Total letters|[A-Z]:" | Select-Object -First 12

# Test 4: File Statistics
Write-Host "`n`n[TEST 4] Showing File Statistics..." -ForegroundColor Yellow
@"
9
test.txt
"@ | .\caesar-cipher.exe 2>$null | Select-String -Pattern "File size|Total chars|Letters|Lines"

Write-Host "`n`n==================================================" -ForegroundColor Cyan
Write-Host "   ALL TESTS COMPLETED!" -ForegroundColor Cyan
Write-Host "==================================================" -ForegroundColor Cyan

Write-Host "`nFiles created:" -ForegroundColor Green
Get-ChildItem *.txt,*.enc | Select-Object Name, Length | Format-Table
