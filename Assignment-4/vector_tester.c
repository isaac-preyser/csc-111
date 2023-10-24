/* vector_tester.c
   CSC 111 - Fall 2023 - Assignment 4

   Some basic tests for the vector functions. You should modify the test cases 
   and/or add your own tests to ensure that your functions are validated
   thoroughly.

   B. Bird - 2023-10-14
*/


#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "matrix_and_vector.h"

const double M_PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127372458700660631558817488152092096282925409171536436789259036001133053054882046652138414695194151160943305727036575959195309218611738193261179310511854807446237996274956735188575272489122793818301194912983367336244065664308602139494639522473719070217986094370277053921717629317675238467481846766940513200056812714526356082778577134275778960917363717872146844090122495343014654958537105079227968925892354201995611212902196086403441815981362977477130996051870721134999999837297804995105973173281609631859502445945534690830264252230825334468503526193118817101000313783875288658753320838142061717766914730359825349042875546873115956286388235378759375195778185778053217122680661300192787661119590921642019893809525720106548586327886593615338182796823030195203530185296899577362259941389124972177528347913151557485724245415069595082953311686172785588907509838175463746493931925506040092770167113900984882401285836160356370766010471018194295559619894676783744944825537977472684710404753464620804668425906949129331367702898915210475216205696602405803815019351125338243003558764024749647326391419927260426992279678235478163600934172164121992458631503028618297455570674983850549458858692699569092721079750930295532116534498720275596023648066549911988183479775356636980742654252786255181841757467289097777279380008164706001614524919217321721477235014144197356854816136115735255213347574184946843852332390739414333454776241686251898356948556209921922218427255025425688767179049460165346680498862723279178608578438382796797668145410095388378636095068006422512520511739298489608412848862694560424196528502221066118630674427862203919494504712371378696095636437191728746776465757396241389086583264599581339047802759009946576407895126946839835259570982582262052248940772671947826848260147699090264013639443745530506820349625245174939965143142980919065925093722169646151570985838741059788595977297549893016175392846813826868386894277415599185592524595395943104997252468084598727364469584865383673622262609912460805124388439045124413654976278079771569143599770012961608944169486855584840635342207222582848864815845602850601684273945226746767889525213852254995466672782398645659611635488623057745649803559363456817432411251507606947945109659609402522887971089314566913686722874894056010150330861792868092087476091782493858900971490967598526136554978189312978482168299894872265880485756401427047755513237964145152374623436454285844479526586782105114135473573952311342716610213596953623144295;


void print_vector(int size, double V[size]){
    for (int i = 0; i < size; i++)
        printf("%.2f ", V[i]);
    printf("\n");
}

int main(){

    double V[] = {1, 2, 3, 4, 5};
    double W[] = {0, 1, 0, 1, 0};
    double X[] = {10, 20, 30, 3.5, 3.6, 3.1415, 1.7};
    double Y[] = {111, 116, 225, 230, 265, 445};
    double Z[] = {0, 0, 0, 999, 999};

    double Q[100]; //Deliberately too large to allow this vector to be used as the output for multiple test cases

    printf("Testing set_vector:\n");
    set_vector(3, Z, 6);
    printf("Result (1): ");
    print_vector(5, Z);
    set_vector(5, Z, 1.87);
    printf("Result (2): ");
    print_vector(5, Z);
    printf("\n");



    printf("Testing mul_vector_by_scalar:\n");
    //Set the first 100 elements of Q to -999
    set_vector(100, Q, -999);
    mul_vector_by_scalar(5, V, Q, 1.5);
    printf("Result (1): ");
    print_vector(5, Q);

    //Now call mul_vector_by_scalar but deliberately decrease
    //the provided size (so the last two elements should remain
    //as -999).
    set_vector(100, Q, -999);
    mul_vector_by_scalar(3, V, Q, 1.5);
    printf("Result (2): ");
    print_vector(5, Q);
    printf("\n");



    printf("Testing dot_product:\n");
    printf("Result (V dot W, size 3): %.2f\n", dot_product(3, V, W));
    printf("Result (V dot W, size 5): %.2f\n", dot_product(5, V, W));
    printf("Result (W dot X, size 5): %.2f\n", dot_product(5, W, X));
    printf("\n");


    printf("Testing norm:\n");
    printf("Result (norm of V, 3 elements): %.2f\n", norm(3, V));
    printf("Result (norm of W, 5 elements): %.2f\n", norm(5, W));
    printf("Result (norm of X, 7 elements): %.2f\n", norm(7, X));
    printf("\n");


    printf("Testing angle_between_vectors:\n");
    printf("Result (V and W, 2 elements): %.2f\n", angle_between_vectors(2, V, W));
    printf("Result (V and W, 3 elements): %.2f\n", angle_between_vectors(3, V, W));
    printf("Result (V and X, 3 elements): %.2f\n", angle_between_vectors(3, V, X));
    printf("\n");



    printf("Testing add_vectors:\n");
    set_vector(100, Q, -999);
    add_vectors(3, V, W, Q);
    printf("Result (V + W, 3 elements): ");
    print_vector(5,Q);

    set_vector(100, Q, -999);
    add_vectors(5, V, W, Q);
    printf("Result (V + W, 5 elements): ");
    print_vector(5, Q);

    set_vector(100, Q, -999);
    add_vectors(6, X, Y, Q);
    printf("Result (X + Y, 6 elements): ");
    print_vector(6, Q);
    printf("\n");


// Test dot_product with orthogonal vectors
double orthogonal_vector1[3] = {1, 0, 0};
double orthogonal_vector2[3] = {0, 1, 0};
assert(dot_product(3, orthogonal_vector1, orthogonal_vector2) == 0);

// Test norm with non-zero vector
double non_zero_vector[3] = {1, 2, 3};
assert(norm(3, non_zero_vector) == sqrt(14));

// Test angle_between_vectors with orthogonal vectors
assert(angle_between_vectors(3, orthogonal_vector1, orthogonal_vector2) == M_PI / 2);

// Test add_vectors with non-zero vectors
double non_zero_result[3];
add_vectors(3, V, non_zero_vector, non_zero_result);
assert(non_zero_result[0] == V[0] + non_zero_vector[0] && non_zero_result[1] == V[1] + non_zero_vector[1] && non_zero_result[2] == V[2] + non_zero_vector[2]);


    // Test dot_product with zero vectors
    double zero_vector[3] = {0, 0, 0};
    assert(dot_product(3, V, zero_vector) == 0);

    // Test norm with zero vector
    assert(norm(3, zero_vector) == 0);

    // Test angle_between_vectors with same vector
    double same_vector[3] = {1, 2, 3};
    assert(angle_between_vectors(3, same_vector, same_vector) == 0);

    // Test add_vectors with zero vectors
    double result[3] = {0, 0, 0};
    add_vectors(3, V, zero_vector, result);
    assert(result[0] == V[0] && result[1] == V[1] && result[2] == V[2]);

    // Test matrix_vector_multiply with identity matrix
    double identity_matrix[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double vector[3] = {1, 2, 3};
    double result_vector[3];
    matrix_vector_multiply(3, 3, identity_matrix, vector, result_vector);
    assert(result_vector[0] == vector[0] && result_vector[1] == vector[1] && result_vector[2] == vector[2]);
       printf("Identity matrix:\n");
    for (int i = 0; i < 3; i++) {
        printf("%f\t", result_vector[i]);
        printf("\n");
    }

    printf("Testing matrix_vector_multiply:\n");

    int row1, col1, row2, col2;

    // Input dimensions of the first matrix
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &row1, &col1);

    // Input dimensions of the second matrix
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &row2, &col2);

    // Check if matrix multiplication is possible
    if (col1 != row2) {
        printf("Matrix multiplication is not possible. Column of the first matrix must be equal to the row of the second matrix.\n");
        return 1;
    }

    double firstMatrix[row1][col1], secondMatrix[row2][col2], resultMatrix[row1][col2];
    printf("Enter the elements of the first matrix:\n");
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col1; j++) {
                scanf("%lf", &firstMatrix[i][j]);
            }
        }
    printf("Enter the elements of the second matrix:\n");
        for (int i = 0; i < row2; i++) {
            for (int j = 0; j < col2; j++) {
                scanf("%lf", &secondMatrix[i][j]);
            }
        }
    // Initialize the result matrix with zeros
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            resultMatrix[i][j] = 0;
        }
    }

    matrix_multiply(row1, col1, col2, firstMatrix, secondMatrix, resultMatrix);
    // Display the result matrix
    printf("Resultant matrix:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            printf("%f\t", resultMatrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
